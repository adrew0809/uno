### Arduino Projects in Modern C++

## Purpose

Can embedded code be expressive, type-safe, modular, and testable?

### Project 2

This solution uses meaningful classes, arrays, variants, and state transitions.
Rather than block for a half second during a blink cycle, this solution immediately
breaks out of the blink when the button is released.

Compiled for Arduino uno.

                  | program size (bytes) | dynamic memory (bytes)
                  +----------------------+-----------------------
    book solution | 1160                 | 9
    this solution | 1168                 | 9
