# language: en
# Project Computer Science xxx
# file 0001-Dummy.feature
#
Feature: Hello World feature
    As a developer starting a new project
    I want to have a dummy feature test
    In order to get started and show that the toolchain works

Scenario Outline: Single dummy says Hello World
    Given  a dummy initialised with <hello> and <world>
     When  I command the dummy to say hello
     Then  the dummy should say <hello world>

Examples:
  | hello     | world          | hello world             |
  | "Hello"   | "World"        | "Hello World"           |
  | "Hallo"   | "Welt"        | "Hallo Welt"             |
  | "Bonjour" | "tout le monde"| "Bonjour tout le monde" |
  | "Hola"    | "mundo"        | "Hola mundo"            |
  | "Hello"   | "vilag"        | "Hello vilag"           |


Scenario Outline: Multiple dummies say Hello World
    Given the following dummies:
    | hello   | world         |
    | Hello   | World         |
    | Hallo   | Welt          |
    | Bonjour | tout le monde |
    | Hola    | mundo         |
    | Hello   | vilag         |

     When I command the dummy <index> to say hello
     Then the dummy should say <hello world>

Examples:
  | index | hello world             |
  | 0     | "Hello World"           |
  | 1     | "Hallo Welt"            |
  | 2     | "Bonjour tout le monde" |
  | 3     | "Hola mundo"            |
  | 4     | "Hello vilag"           |
