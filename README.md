# Supowit's algorithm

## Requirement

+ C++ 11+
+ CMake 3.0.0+

## Input format

+ Filename: input
+ Content

    ```
    [number of points]
    [point_1 of chord_1] [point_2 of chord_1] (i.e. a chord)
    [point_1 of chord_2] [point_2 of chord_2]
    .
    .
    .
    [point_1 of chord_n] [point_2 of chord_n]
    0
    
    ```

+ The number of points mustn't be equal or larger than the max value of `unsigned short`.
+ You can generate input file automatically by the PHP script. (need PHP CLI 7.0+)

    ```
    php input_gen.php [chord number] input
    ```

## Output format

+ Filename: output
+ Content

    ```
    [number of chords]
    [point_1 of chord_1] [point_2 of chord_1] (i.e. a chord)
    [point_1 of chord_2] [point_2 of chord_2]
    .
    .
    .
    [point_1 of chord_n] [point_2 of chord_n]

    ```

## Get started

```
make run
```
