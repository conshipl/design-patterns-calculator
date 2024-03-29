# C++ Calculator

My final project for Software Design/Patterns course at IUPUI.

A simple calculator that takes a user input infix expression in the form of "( 5 + 7 ) / 2" and returns the result.

It can perform add, subtract, divide, multiply, and modulo operations, and behaves correctly in the presence of parentheses.

__The project showcases the following Gang of Four patterns:__
* Wrapper/Facade
* Command
* Template
* Abstract Factory
* Flyweight
* Composite
* Visitor
* Builder
* Strategy

## Informal Diagram: ##

[![calculator](https://github.com/conshipl/design-patterns-calculator/blob/master/calculator.jpg)](calculator.jpg)


## Backstory
Initially, I was tasked with building an Array ADT that acts as a Wrapper/Facade for the underlying C++ array class, extending its functionality with features such as resize, shrink, slice, fill, find, + and = overloading, etc. The Array class is also a generic/template, allowing it to create an array out of any provided type. Then, utilizing my custom Array class, I built Stack and Queue ADTs that perform all expected operations (push, enqueue, pop, etc.). Next, I used the Stack and Queue ADTs to make a basic calculator that accepts a user input infix expression in the form of "( 5 + 7 ) / 2", parses it into either a postfix expression or expression tree, evaluates, and returns the correct result.

The calculator functions by performing preprocessing on the user input infix expression to determine the best strategy: a postfix expression or an expression tree. If the postfix strategy is selected, then the expression is sorted from an infix string into a postfix Queue of Command objects waiting to execute and return the result. If it's the expression tree strategy, then the expression is built from an infix string into a tree structure (Composite Pattern) where a Visitor can visit each node and accumulate state to return the result.

## Project Status
Working.

It was a lot of hard work and I'm proud of it, but it was created during the school year with a full course load and deadlines, so it needs some fine-tuning around the edges.

## Known Issues
* Inconsistent commenting style (some files have none or half done; it's a lot of files and I ran out of time on the initial submission :) )
* Need to delete professor comments/replies
* A few lines of dead or currently unimplemented code (Stack_Factory isn't using a stack anymore, for example; it got switched to Flyweight Pattern, but stack member variable was never deleted)
* Visitor Pattern isn't properly implemented (I defeated the spirit of the pattern by returning the result through recursion instead of having the Visitor accumulate state)
* Parenthesis Command/Node is violating good coding practice (it's not really a Command or a Node, it's just a placeholder; could refactor to use recursion and avoid creating objects for parentheses)
* Could implement Iterator Pattern for Array/Stack/Queue
* Could implement Proxy Pattern (smart pointers)
* Infix expression isn't being preprocessed (I still need to figure out what heuristics to apply to determine the correct strategy, postfix or expression tree; currently it always does expression tree)

## Technologies
C++, MakefileProjectCreator, makefiles, templates, generics, software design patterns, abstraction
