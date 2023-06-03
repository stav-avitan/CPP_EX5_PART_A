#include "doctest.h"
#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;

TEST_CASE(" Test 1 - Container Size and Element Removal")
{
	 MagicalContainer container;

    CHECK(container.size() == 0);

    int numOfElements = 10;

    for (int i = 1; i<=numOfElements; i++){
            container.addElement(i);
            CHECK(container.size()==i);
    }

      

    for (int i = 1; i<=numOfElements; i++){
            container.removeElement(i);
    }

    CHECK(container.size()==0);

}

TEST_CASE("Test 2 - Prime Iterator") {
    MagicalContainer mc;
    mc.addElement(7);
    mc.addElement(12);
    mc.addElement(5);
    mc.addElement(11);

    MagicalContainer::PrimeIterator primesIter(mc);

    // Retrieve the value pointed to by the iterator and compare it with 5
    CHECK(*primesIter == 5);

    // Move the iterator to the next element
    ++primesIter;

    // Retrieve the value pointed to by the iterator and compare it with 7
    CHECK(*primesIter == 7);

    // Move the iterator to the next element
    ++primesIter;

    // Check if the iterator has reached the end
    CHECK(primesIter == primesIter.end());
}


TEST_CASE("Test 3 - Ascending Iterator") {
    MagicalContainer container;
    container.addElement(7);
    container.addElement(2);
    container.addElement(5);

    MagicalContainer::AscendingIterator ascenIter(container);

    int expectedValues[] = {2, 5, 7};

    for (int i= 0; ascenIter != ascenIter.end(); ++ascenIter, ++i) {
        // Retrieve the value pointed to by the iterator and compare it with the expected value
        CHECK(*ascenIter == expectedValues[i]);
    }

    // Check if the iterator has reached the end
    CHECK(ascenIter == ascenIter.end());

}

TEST_CASE("Test 4 - Side Cross Iterator"){
    MagicalContainer container;
    container.addElement(8);
    container.addElement(11);
    container.addElement(6);

    MagicalContainer::SideCrossIterator crossIter(container);

    int expectedValues[] = {6, 11, 8};
 

    for (int i = 0; crossIter != crossIter.end(); ++crossIter, ++i) {
        // Retrieve the value pointed to by the iterator and compare it with the expected value
        CHECK(*crossIter == expectedValues[i]);
    }

    // Check if the iterator has reached the end
    CHECK(crossIter == crossIter.end());
}

TEST_CASE("6 - Custom Iterator Comparison and Ordering") {
    MagicalContainer myContainer;
    myContainer.addElement(7);
    myContainer.addElement(12);
    myContainer.addElement(5);

    MagicalContainer::AscendingIterator myAscIter1(myContainer);
    MagicalContainer::AscendingIterator myAscIter2(myContainer);
    MagicalContainer::SideCrossIterator myCrossIter1(myContainer);
    MagicalContainer::SideCrossIterator myCrossIter2(myContainer);
    MagicalContainer::PrimeIterator myPrimesIter1(myContainer);
    MagicalContainer::PrimeIterator myPrimesIter2(myContainer);

    CHECK(myAscIter1 == myAscIter2);
    CHECK(myCrossIter1 == myCrossIter2);
    CHECK(myPrimesIter1 == myPrimesIter2);

    ++myAscIter1;
    ++myCrossIter1;
    ++myPrimesIter1;

    CHECK(myAscIter1 != myAscIter2);
    CHECK(myAscIter1 > myAscIter2);
    CHECK(myAscIter2 < myAscIter1);

    CHECK(myCrossIter1 != myCrossIter2);
    CHECK(myCrossIter1 > myCrossIter2);
    CHECK(myCrossIter2 < myCrossIter1);

    CHECK(myPrimesIter1 != myPrimesIter2);
    CHECK(myPrimesIter1 > myPrimesIter2);
    CHECK(myPrimesIter2 < myPrimesIter1);

    ++myAscIter2;
    ++myCrossIter2;
    ++myPrimesIter2;

    CHECK(myAscIter1 == myAscIter2);
    CHECK(myCrossIter1 == myCrossIter2);
    CHECK(myPrimesIter1 == myPrimesIter2);
}



