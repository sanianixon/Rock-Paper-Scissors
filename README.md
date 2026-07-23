# Rock Paper Scissors — Adaptive Opponent

A browser-based Rock Paper Scissors game where the computer adapts to the player’s previous choices.

During the first few rounds, the computer selects moves randomly. As the game continues, it analyses the player’s move history, predicts their most frequently used move, and chooses the appropriate counter-move.

## Demo

<p align="center">
  <img src="demo.gif" width="850" alt="Rock Paper Scissors gameplay demo">
</p>

## Features

- Play directly in the browser
- Choose the total number of rounds
- Track player and computer scores
- Random computer moves during the opening rounds
- Player-history-based move prediction
- Automatic counter-move selection
- Final winner announcement
- Restart the game without refreshing the page
- Responsive card-based interface

## How the opponent works

The computer uses two strategies.

### Opening rounds

During the first two rounds, the computer selects Rock, Paper, or Scissors randomly.

### Adaptive rounds

After enough player history is available, the computer:

1. Counts how often the player selected each move.
2. Identifies the player’s most frequently used move.
3. Predicts that the player may choose it again.
4. Selects the move that counters that prediction.

For example:

- If the player frequently selects Rock, the computer chooses Paper.
- If the player frequently selects Paper, the computer chooses Scissors.
- If the player frequently selects Scissors, the computer chooses Rock.

If multiple moves are equally frequent, one of them is selected randomly as the prediction.

This is a simple pattern-based strategy rather than a machine-learning model.

## Technology stack

- HTML5
- CSS3
- JavaScript
- DOM manipulation
- JavaScript event handling

## Run locally

Clone the repository:

```bash
git clone https://github.com/sanianixon/Rock-Paper-Scissors.git
