# Radar---Air-Traffic-Simulation-Panel

# Before cloning the repository
Having the csfml library installed: https://www.sfml-dev.org/download/csfml/

# How to run the game
```
$ ./my_radar path/to/file
OR
$ ./my_radar -h
```
+ Example files can be found in the script/ folder
  
# Preview

# Requirements
# Must
[x] The program must take exactly one parameter.

[x] The program must accept any filepath as argument. It corresponds to the file containing the script for
   the simulation containing characters and integers.
   
[] The program must displayed an error message if the script is not found or incorrect.

[x] Your window must be 1920x1080 pixels.

[x] The window must be closed using events.

[x] The program must display aircrafts’ hitbox and control towers’ areas.

[x] The program must manage as many displayed entities as possible. -> 200

[x] Aircrafts must have 20x20 square shaped hitboxes.

[x] Aircrafts’ hitbox and sprite must be axis-aligned.

[x] Control towers must have circled shaped control areas.


# Should
[] The program should display and update a timer in seconds at the top-right corner of the window.

[x] The program should stop once all aircrafts have landed on or have been destroyed.

[] Aircrafts should be able to take off after a given delay.

[x] Aircrafts and control towers should be displayed using sprites.

[x] The program should accept the “-h” option, then display the usage.

[x] The program should be able to switch visibility of hitboxes and areas by pressing the key ‘L’.

[x] The program should be able to switch visibility of entities’ sprites by pressing the key ‘S’.

[x] Possible user interactions should be explicitly displayed in the usage.

# Could

[] Aircrafts’ hitbox and size could be in a 3D space.

[] Aircrafts’ hitbox could follow the sprite boundary.

[x] Aircrafts’ hitbox and sprite could rotate depending on the aircrafts’ direction.

[] Aircrafts’ hitbox could have different sizes.

[] Control towers’ areas could cross any side of the screen and affect the opposite one.

[] The program could manage floating numbers coming from the script.

