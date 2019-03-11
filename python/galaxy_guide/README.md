### User Guide

### Design Doc
The source files are under `src/galaxy` :
```
./src/galaxy
├── GalaxyGuide.py
├── GalaxyMath.py
├── GalaxyQA.py
├── TestGalaxyMath.py
├── TestGalaxyQA.py
└── __init__.py
```
* `GalaxyGuide.py` is the entrance of this program.
* `GalaxyQA.py` get your input, process it, and print answer.
* `GalaxyMath.py` contains 3 classes:
  * `GalaxyCredits` stores Credits, provide set() and get() function.
  * `GalaxyRomanWord` stores the galaxy words and corresponding Roman letter.
  * `GalaxyRoman` provide number_to_roman() and roman_to_number() function.
* `TestGalaxyQA.py` is the testing file of `GalaxyQA.py`
* `TestGalaxyMath.py` is the testing file of `GalaxyMath.py`

#### Run the program:
You can start the program and input from file or console:
1. From file
```
./src/galaxy/GalaxyGuide.py < input/case1
```
2. From console
```
./src/galaxy/GalaxyGuide.py
```
Input content:
```
glob is I
prok is V
pish is X
tegj is L
glob glob Silver is 34 Credits
glob prok Gold is 57800 Credits
pish pish Iron is 3910 Credits
how much is pish tegj glob glob ?
how many Credits is glob prok Silver ?
how many Credits is glob prok Gold ?
how many Credits is glob prok Iron ?
how much wood could a woodchuck chuck if a woodchuck could chuck wood ?
```
3. The output will be:
```
pish tegj glob glob is 42
glob prok Silver is 68 Credits
glob prok Gold is 57800 Credits
glob prok Iron is 782 Credits
I have no idea what you are talking about
```
4. Notice
The input content can only be in below four format:

  * Tell the GalaxyGuide System one Galaxy Word and corresponding Roman Letter.

    Roman Letter can only be `I`, `V`, `X`, `L`, `C`, `D`, `M`.

    ```
    glob is I
    ```

  * Tell the GalaxyGuide System one meterial and corresponding Credits.

    Credits number can be integer or float, but will only print integer when you ask `how many Credits is glob prok Silver ?`

    ```
    glob glob Silver is 34 Credits
    ```

  * Ask the GalaxyGuide System how much is a Roman Number which is expressed by Galaxy Word.

    Mush add `?` at the end of the scentence.
    ```
      how much is pish tegj glob glob ?
    ```

  * Ask the GalaxyGuide System how many Credits of one meterial.

    Mush add `?` at the end of the scentence.
    ```
    how many Credits is glob prok Silver ?
    ```

#### Run the testing file:
For example, run `TestGalaxyMath.py`:
```
./src/galaxy/TestGalaxyMath.py -v
```
The output will be:
```
test_is_roman_letter (__main__.TestGalaxyRoman) ... ok
test_is_roman_letter_invaild_input (__main__.TestGalaxyRoman) ... ok
test_number_to_roman (__main__.TestGalaxyRoman) ... ok
test_number_to_roman_type_check (__main__.TestGalaxyRoman) ... ok
test_number_to_roman_value_check (__main__.TestGalaxyRoman) ... ok
test_roman_to_number (__main__.TestGalaxyRoman) ... ok
test_roman_to_number_invalid_input (__main__.TestGalaxyRoman) ... ok
test_roman_to_number_order (__main__.TestGalaxyRoman) ... ok
test_roman_to_number_repeated_numerals (__main__.TestGalaxyRoman) ... ok
test_set_get (__main__.TestGalaxyRomanWord) ... ok
test_set_invalid_input (__main__.TestGalaxyRomanWord) ... ok

----------------------------------------------------------------------
Ran 11 tests in 0.005s

OK
```
