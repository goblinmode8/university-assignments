#!/bin/bash

# NAME : Felicity Lester & Sam Arshad
# CS 4350 – Unix Systems Programming
# Section Number : 251
# Assignment Number : 2
# Due Date : 2 / 12 / 2025 no later than 5:15 pm.
#
# 1. Display the integer arguments that are entered.
# 2. The smallest of the integer arguments.
# 3. The largest of the integer arguments.
# 4. The sum of the 3 integer arguments.
# 5. The product of the 3 integer arguments.
# 6. The average of the 3 integer arguments.
# 7. The square of each integer argument.
# 8. Determine that each integer argument is positive, negative.
# 9. Determine whether each integer argument is odd, or even.
# 10. Find all even numbers between one and the first integer
#   argument assuming that the number is positive. If the number is
#   negative, then find all even numbers between that number and one.
# 11. Find all odd numbers between one and the second integer
#   argument Assuming that the number is positive. If the number is
#   negative, then find all the odd number between that number to one.
# 12. Assuming that the last integer is an integer greater than zero,
#   find the factorial of that last integer argument. Display an error
#   message if it is negative.
# 13. Assuming that the second integer is a positive integer greater
#   than zero, determine whether the second integer argument is a
#   prime number. Should the second integer is negative , find and
#   display the positive of that number , then determine whether the
#   number is prime.

# Check if exactly three arguments are given
if [ $# -ne 3 ]; then
    echo "Error: You must enter exactly three integers."
    echo "Usage: ./myintegers.sh X Y Z"
    exit 1
fi

# Assign input arguments
 X=$1
 Y=$2
 Z=$3

# Display the entered numbers
echo "1. You Entered $X $Y $Z"


# Display the smallest number
if [ $X -lt $Y ] && [ $X -lt $Z ]; then
    SMALLEST=$X
elif [ $Y -lt $X ] && [ $Y -lt $Z ]; then
    SMALLEST=$Y
else
    SMALLEST=$Z
fi

echo "2. The smallest integer is $SMALLEST"


# Display the largest number
# use -ge not -gt because then Z becomes default when #s are equal
if [ $X -ge $Y ] && [ $X -ge $Z ]; then
    LARGEST=$X
elif [ $Y -ge $X ] && [ $Y -ge $Z ]; then
    LARGEST=$Y
else
    LARGEST=$Z
fi

echo "3. The largest integer is $LARGEST"

# Calculate the sum
SUM=$((X + Y + Z))
echo "4. The sum is $X + $Y + $Z = $SUM"


# Calculate the product
PRODUCT=$((X * Y * Z))
echo "5. The product is $X * $Y * $Z = $PRODUCT"

# Calculate the average
# bc = basic calculator
# scale=2 ensures 2 decimal places
AVERAGE=$(echo "scale=2; ($X + $Y + $Z) / 3" | bc)
echo "6. The average is ($X + $Y + $Z) / 3 = $AVERAGE"

# Square of each integer
SQUARE_X=$((X * X))
SQUARE_Y=$((Y * Y))
SQUARE_Z=$((Z * Z))
echo "7. The square is $X*$X = $SQUARE_X, $Y*$Y = $SQUARE_Y, $Z*$Z = $SQUARE_Z "


# Positive, Negative, or zero
# Check if X is positive, negative, or zero
if [ $X -gt 0 ]; then
    POSNEG_X="positive"
elif [ $X -lt 0 ]; then
    POSNEG_X="negative"
else
    POSNEG_X="zero"
fi

# Check if Y is positive, negative, or zero
if [ $Y -gt 0 ]; then
    POSNEG_Y="positive"
elif [ $Y -lt 0 ]; then
    POSNEG_Y="negative"
else
    POSNEG_Y="zero"
fi

# Check if Z is positive, negative, or zero
if [ $Z -gt 0 ]; then
   POSNEG_Z="positive"
elif [ $Z -lt 0 ]; then
   POSNEG_Z="negative"
else
   POSNEG_Z="zero"
fi

echo "8. $X is $POSNEG_X, $Y is $POSNEG_Y, $Z is $POSNEG_Z "

# Integer odd or even
# Check if X is odd or even
if [ $(( X % 2)) -eq 0 ]; then
    ODDEVEN_X="even"
else
    ODDEVEN_X="odd"
fi

# Check if Y is odd or even
if [ $(( Y % 2)) -eq 0 ]; then
    ODDEVEN_Y="even"
else
    ODDEVEN_Y="odd"
fi

# Check if Z is odd or even
if [ $(( Z % 2)) -eq 0 ]; then
    ODDEVEN_Z="even"
else
    ODDEVEN_Z="odd"
fi

echo "9. $X is $ODDEVEN_X, $Y is $ODDEVEN_Y, $Z is $ODDEVEN_Z "

# All even numbers b/t 1 and first integer
echo -n "10. All even numbers between 1 and $X are: "
for ((j=1; j<=$X; j++)); do
    if [ $((j % 2)) -eq 0 ]; then
       echo -n "$j "  # Print each even number with a space
    fi
done
echo


# All odd numbers b/t 1 and second integer
echo -n "11. All odd numbers between 1 and $Y are: "
for ((j=1; j<=$Y; j++)); do
    if [ $((j % 2)) -ne 0 ]; then
       echo -n "$j "
    fi
done
echo

# Factorial of last integer
 if [[ $Z -ge 0 ]]; then 
    factorial=1

    echo -n "12. Factorial of $Z is: "

    for((i=2;i<=Z;i++))
    do
        factorial=$((factorial *i))
    done

    echo $factorial
fi

# Second integer prime
if [ $Y -lt 2 ]; then
    echo "13. $Y is not a prime number"
elif [ $Y -eq 2 ]; then
    echo "13. $Y is a prime number"
elif [ $((Y % 2)) -eq 0 ]; then
    echo "13. $Y is not a prime number"
else
    is_prime=true
    for ((i=3; i*i<=$Y; i+=2))  # Check odd numbers up to sqrt(num2)
    do
      	if [ $((Y % i)) -eq 0 ]; then
            is_prime=false
            break
        fi
    done

    if $is_prime; then
        echo  "13. $Y is a prime number"
    else
        echo  "13. $Y is not a prime number"
    fi
fi


printf "\n"
echo "End of script"

echo "Felicity Lester & Sam Arshad - 2 - 12 - 2025"
