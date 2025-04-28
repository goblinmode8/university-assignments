# NAME : Felicity Lester  CS 4350 – Unix Systems Programming
# Serial Number : 251
# Assignment Number : 3
# Due Date : 2 / 24 / 2025  No later than 5:15 pm


#!/bin/bash

printf "\n"
echo "Shell Programming By Felicity Lester"
printf "\n"

echo "1. Creating a new file zNew.txt"
cat > zNew.txt <<EOF
Spring 2025
CS4350
Section #
251
scripts and shell programming using
zeus ide
@ TEXAS STATE UNIVERSITY
EOF
printf "\n\n"

echo "2. The content of the created file is : "
# read .txt file
cat zNew.txt
printf "\n\n"

echo "3. All lines with alphabet characters : "
grep '[[:alpha:]]' zNew.txt 
printf "\n\n"

echo "4. All lines with digits : "
grep '[[:digit:]]' zNew.txt
printf "\n\n"

echo "5. All lines with lowercase characters : "
grep '[[:lower:]]' zNew.txt
printf "\n\n"

echo "6. All lines with uppercase characters : "
grep '[[:upper:]]' zNew.txt
printf "\n\n"

echo "7. All lines with alphanumeric characters : "
grep '[[:alnum:]]' zNew.txt
printf "\n\n"

echo "8. All lines with punctuation characters : "
grep '[[:punct:]]' zNew.txt
printf "\n\n"

echo "9. All the lines with the letter s followed by space : "
grep 's[[:space:]]' zNew.txt
printf "\n\n"

echo "10. All the lines with the word zeus followed by space : "
grep 'zeus[[:space:]]' zNew.txt
printf "\n\n"

echo "11. All the line that the word programming appears at the end of the line : "
grep 'programming$' zNew.txt
printf "\n\n"

echo "12. All the lines that the word Spring appears at the beginning of the sentence : "
grep '^Spring' zNew.txt
printf "\n\n"

echo "13. All lines that has a word that starts with C and ends with 0 : "
grep '\bC[^ ]*0\b' zNew.txt
printf "\n\n"

echo "14. All lines that contain a word that starts with s and end with l : "
grep '\bs[^ ]*l\b' zNew.txt
printf "\n\n"

echo "15. Deleting the existing File zNew.txt "
rm zNew.txt
printf "\n\n"

echo "16. Display the content of zNew.txt : "
cat zNew.txt

printf "\n\n"
echo "Prepared by Felicity Lester :)"
echo "2 – 24 - 2025"
