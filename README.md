## I. About

Fully functional chess program supporting the following features:

- All standard chess moves, checks, checkmates, pawn promotion, [en passant](https://en.wikipedia.org/wiki/En_passant), castling... etc.
- Both a text and a graphical interface.
- 3 game modes (human vs. human, human vs. computer, computer vs. computer)
  - and the following levels of computer difficulty:
    - level 1: random moves.
    - level 2: preference for placing the opposing king in check/checkmate and capturing pieces.
    - level 3: all of the above + a preference for avoiding capture (incomplete)
- A 'setup' mode, enabling players to manually place pieces at positions across the board
- Memory management handled via STD containers + smart pointers


## II. Technical Details

- Object Oriented Programming
- MVC
- Observer pattern (pub-sub)

UML:
[UML](FinalChessUML.png)


## III. Execution and Dependencies

Requires: C++ 14 and X11.

Build and run:

```
make
./chess
```
