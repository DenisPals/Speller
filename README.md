# Speller - A program that spell-checks a file
## Complexity
This spell-checker takes a dictionary and a file as input and spell-checks the file. To achieve this, the dictionary is read into memory and each word is stored in a hash table. Then the program iterates over each word in the input file and checks if the word is contained in the hash table (dictionary) and stores misspelled words. The wrong words are displayed in the command-line.

The challenge was:
* The implementation of the load function. 
* The implementation of the hash function. 
* The implementation of the size function. 
* The implementation of the check  function. 
* The implementation of the unload  function. 

This is a course related project and part of the problemset in Harvards CS50x week 5.

## Files
**speller.c** contains the code that measures the time it takes to read the dictionary into memory and prints misspelled words.

**dictionary.c** contains the code that reads the dictionary into memory, a hashfunction that hashes each word from the dictionary, a size function that counts howmany words the dictionary contains, a check function that checks if a word is contained in the dictionary and an unload function that frees dynamically allocated heap memory. The hashfunction is simple and not taken from any online source but self-made.

**keys**
The keys folder contains a number of misspelled words to test the progeram.

**texts** folder contains a number of texts that can be spell-checked by the program

**dictionaries** contains a small and a large dictionary, the small's purpose was initialy to test the basic functionality without needing to iterate over 143000 words of the large dictionary.

## How to run
To run this program, a C compiler must be installed. The best way is to run it is to use a Linux enviroment like WSL for windows (if not using Linux) and to run (after compiling): 
Grayscale:
> ./speller texts/YOURTEXT.txt

This will automatically use the large dictionary and output the wrong words from your text.

## Output
```
./speller texts/lalaland.txt
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]
```