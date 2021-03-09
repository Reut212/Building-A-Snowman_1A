#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code")
{                                     //HNLRXYTB
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    /*
      _===_
      (.,.)
      ( : )
      ( : )
      */
    CHECK(nospaces(snowman(23323334)) == nospaces("  ___ \n .....\n\\(o_O)\n (> <)\n  (   )"));
    /*
        ___ 
       .....
      \(o_O)
       (> <)
       (   )
      */
    CHECK(nospaces(snowman(33232124)) == nospaces("  _  \n /_\\ \n\\(o_O)\n (] [)>\n(   )"));
    /*
        _
       /_\
     \(o_O)
      (] [)>
      (   )
    */
    CHECK(nospaces(snowman(41331111)) == nospaces(" ___ \n(_*_)\n(O,-)\n<( : )>\n( : )"));
    /*
      ___ 
     (_*_)
     (O,-)
    <( : )>
     ( : )
    */
    CHECK(nospaces(snowman(33322111)) == nospaces("  _  \n /_\\ \n\\(o_O)\n( : )>\n( : )"));
    /*
       _  
      /_\ 
    \(o_O)
     ( : )>
     ( : )
    */
    CHECK(nospaces(snowman(11434121)) == nospaces("_===_\n\\(-,O)\n (] [)>\n( : )"));
    /*
     _===_
    \(-,O)
     (] [)>
     ( : )
    */
    CHECK(nospaces(snowman(34114122)) == nospaces("  ___ \n .....\n(. .)\n (] [)>\n( : )\n(" ")"));
    /*
      ___ 
     .....
     (. .)
     (] [)>
     (" ")
    */
    CHECK(nospaces(snowman(42434433)) == nospaces(" ___ \n(_*_)\n(O.-)\n(> <)\n(___)"));
    /*
     ___ 
    (_*_)
    (O.-)
    (> <)
    (___)
    */
    CHECK(nospaces(snowman(33444444)) == nospaces("  _  \n /_\\ \n(-_-)\n(   )\n (   )"));
    /*
      _  
     /_\
    (-_-)
    (   )
    (   )
    */
   CHECK(nospaces(snowman(13114441)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    /*
    _===_
    (._.)
    (   )
    ( : )
    */
   CHECK(nospaces(snowman(24443322)) == nospaces("  ___ \n .....\n\\(- -)/\n (] [)\n(" ")"));
    /*
      ___ 
     .....
    \(- -)/
     (] [)
     (" ")
    */
   CHECK(nospaces(snowman(33234441)) == nospaces("  _  \n /_\\ \n(O_o)\n(   )\n ( : )"));
    /*
      _  
     /_\ 
    (O_o)
    (   )
    ( : )
    */
   CHECK(nospaces(snowman(11334422)) == nospaces("_===_\n\\(O.O)\n (] [)\n(" ")"));
    /*
     _===_
     (O.O)
     (] [)
     (" ")
    */
}

TEST_CASE("Bad snowman code")
{
	CHECK_THROWS(snowman(55555555)); // Not a valid input
    CHECK_THROWS(snowman(111)); // A short number
    CHECK_THROWS(snowman(12345679)); // A number with some wrong digits in different places
    CHECK_THROWS(snowman(12341235)); // A number with a wrong digit
    CHECK_THROWS(snowman(444444444)); // A number with 9 digits
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n\\(-,O)\n (] [)>\n( : )")); // Unequal content
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n\\(O.O)\n (] [)\n(" ")")); // Unequal content
    CHECK(nospaces(snowman(11114411)) == nospaces(" ___ \n(_*_)\n(O.-)\n(> <)\n(___)")); // Unequal content
}