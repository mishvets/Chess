# Chess

Basic game


## How to play

### Running the game

```
make
./chess
```
### In game
First you should choose game: new game or load previous game that was saved.

Then the game board and a list of available teams will be displayed.
##### Board
```
                   W H I T E
      a    b    c    d    e    f    g    h
    ———— ———— ———— ———— ———— ———— ———— ————
 1 | WR | WN | WB | WQ | WK | WB | WN | WR | 1
    ———— ———— ———— ———— ———— ———— ———— ————
 2 | WP | WP | WP | WP | WP | WP | WP | WP | 2
    ———— ———— ———— ———— ———— ———— ———— ————
 3 |    |    |    |    |    |    |    |    | 3
    ———— ———— ———— ———— ———— ———— ———— ————
 4 |    |    |    |    |    |    |    |    | 4
    ———— ———— ———— ———— ———— ———— ———— ————
 5 |    |    |    |    |    |    |    |    | 5
    ———— ———— ———— ———— ———— ———— ———— ————
 6 |    |    |    |    |    |    |    |    | 6
    ———— ———— ———— ———— ———— ———— ———— ————
 7 | BP | BP | BP | BP | BP | BP | BP | BP | 7
    ———— ———— ———— ———— ———— ———— ———— ————
 8 | BR | BN | BB | BQ | BK | BB | BN | BR | 8
    ———— ———— ———— ———— ———— ———— ———— ————
      a    b    c    d    e    f    g    h
                   B L A C K
```
##### List of command
```
Usage : [COMMAND]
        -m [colFrom][rowFrom] [colTo][rowTo]         move figure;
        -s                                           save this game;
        -r                                           start new game;
        -q                                           quit from game;

```
Example: 
1. For **basic move** the knight from b1 to a3 during the move of white, you must write:
`-m b1 a3`
2. For **castling**, it is necessary that the king and the tour do not move before that and there are no figures between them. 
Then for a long castling white figures:
`-m e1 c1`, for short castling: `-m e1 g1`
3. **En passant** - it is a special pawn capture that can only occur immediately after a pawn makes a move of two squares from its starting square, and it could have been captured by an enemy pawn had it advanced only one square. The opponent captures the just-moved pawn "as it passes" through the first square. The result is the same as if the pawn had advanced only one square and the enemy pawn had captured it normally.
````
                   W H I T E
        a    b    c    d    e    f    g    h
      ———— ———— ———— ———— ———— ———— ———— ————
   1 | WR | WN | WB | WQ | WK | WB | WN | WR | 1
      ———— ———— ———— ———— ———— ———— ———— ————
   2 | WP |    | WP | WP | WP | WP | WP | WP | 2
      ———— ———— ———— ———— ———— ———— ———— ————
   3 |    |    |    |    |    |    |    |    | 3
      ———— ———— ———— ———— ———— ———— ———— ————
   4 |    |    |    |    |    |    |    |    | 4
      ———— ———— ———— ———— ———— ———— ———— ————
   5 | BP | WP |    |    |    |    | BP |    | 5
      ———— ———— ———— ———— ———— ———— ———— ————
   6 |    |    |    |    |    |    |    |    | 6
      ———— ———— ———— ———— ———— ———— ———— ————
   7 |    | BP | BP | BP | BP | BP |    | BP | 7
      ———— ———— ———— ———— ———— ———— ———— ————
   8 | BR | BN | BB | BQ | BK | BB | BN | BR | 8
      ———— ———— ———— ———— ———— ———— ———— ————
        a    b    c    d    e    f    g    h
                     B L A C K
  
  <White> Enter command: -m b5 a6

                     W H I T E
        a    b    c    d    e    f    g    h
      ———— ———— ———— ———— ———— ———— ———— ————
   1 | WR | WN | WB | WQ | WK | WB | WN | WR | 1
      ———— ———— ———— ———— ———— ———— ———— ————
   2 | WP |    | WP | WP | WP | WP | WP | WP | 2
      ———— ———— ———— ———— ———— ———— ———— ————
   3 |    |    |    |    |    |    |    |    | 3
      ———— ———— ———— ———— ———— ———— ———— ————
   4 |    |    |    |    |    |    |    |    | 4
      ———— ———— ———— ———— ———— ———— ———— ————
   5 |    |    |    |    |    |    | BP |    | 5
      ———— ———— ———— ———— ———— ———— ———— ————
   6 | WP |    |    |    |    |    |    |    | 6
      ———— ———— ———— ———— ———— ———— ———— ————
   7 |    | BP | BP | BP | BP | BP |    | BP | 7
      ———— ———— ———— ———— ———— ———— ———— ————
   8 | BR | BN | BB | BQ | BK | BB | BN | BR | 8
      ———— ———— ———— ———— ———— ———— ———— ————
        a    b    c    d    e    f    g    h
                     B L A C K
  ````

## Running the tests

For run unit tests:
````
cd Tests/
make
./unitTest
````

### Technical requirements / limitations:

1.	Programming language: C++
2.	External libraries: STL only
3.	Platform: Linux

