Project idea was taken from [https://www.fluentcpp.com/2018/06/29/7-more-ways-to-get-better-at-c-this-summer-2018-edition/[(Fluent C++).
To perserve the exercise, an excerpt can be found here:

# Project #2: Title Case

Look at the headline of this post “7 More Ways to Get Better at C++ This Summer (2018 Edition)”.
Most words start with a capital letter, but not all (for example, “at” and “to” don’t).
This is called Title Case.

Project #2 is about making a library with the clearest interface possible that takes in a string, and outputs a string containing the same contents but in Title Case.

The point is to get more experience with ranges and the STL, design an clear API, and implement a library with expressive code. All of which are precious tools for everyday work.

The requirements of this project can be phased into several steps:

## Step 1: Basic Title Case

For each word in a sentence, make all of its letters lower case, except the first one that would be in upper case.

There is a list of “exceptions” words that need to be entirely in lower case, including their first letter.
This lists includes “at” and “to”, along with another dozen words.
For the sake of this project let’s say that the list of exceptions is: a, an, the, at, by, for, in, of, on, to, and, as and or.

Note that in all cases, the first word of the string must start with a capital letter.

## Step 2: Title Case with customizations

Make the list of exceptions customizable: the library user can add new exceptions, replace the list with their own, or add words that should not be changed by the library.

An additional requirement is that words in all caps should be left as is (“STL” must remain “STL”, and not be changed into “Stl”), but the library user should be able to opt-out of this feature.

## Step 3: Other capitalizations

Title Case is one of the various forms of capitalisation there is.
Other examples include UPPER CASE, lower case, snake_case, Start case, and so on.

Implement at least two other forms of capitalizations in the library, by reusing as much code as possible from the previous steps.
The point of this step is to make a smooth introduction of new features into existing code via a form of polymorphism (runtime, static, other… you choose).

There is no specific requirement on the form of the API, because that’s part of the project:
design an interface that’s easy to understand and use.
And since you’re starting from scratch, it should be easy to write unit tests around your library, and even develop it with TDD if you feel in the mood.
