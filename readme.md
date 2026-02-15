Converting a real number to a fraction.

Any real number can be converted to a fraction, but please dont ask me to prove it!
In this program, the fraction is found by an itterative procdure, which finds the next whole number which can be used to make the remaining ciffers of the real number.

Is this just some mathmatics hocus-pocus that cannot be used for anything?
No, I have actually used it when I was programming a small controller which was not able to calculate real numbers, but I had to multiply an integer with some real number.
Now I could just calculate this: NewNumber = ( 31 x Number ) / 25
This calculation actually calculated: NewNumber = (int)(1.24 * Number)
See below how I found this!

To start, lets take a number x = 1.25
If we look at the remainer of the number, it is 0.25
If we take the reciproc of 0.25, we get 4. Therefor 1.25 can be written as 1 + 1 / 4 = 5 / 4

Lets take x = 1.24
The remainder is now 0.24 and the reciproc is 4.1666667
First try will then be: 5 / 4 = 1.25
The error is: abs( 1.25 / 1.24 – 1 ) = 8064ppm
We now continue with 4.166667 and see how can we make the remainder of this number to a fraction! The reciproc of 0.166667 = 6.
This means that 1.24 can be written as: 1 + 1 / (4 + 1 / 6)
This can be reduced to (by multiplying top and bottom of the last fraction with 6): 1 + 6 / ( 24 + 1)
This means that 1.24 = 1 + 6 / 25, which equals 1.24 = 31 / 25
The error is now zero, and we have found a fraction that represents the real number.

I was in school told, that PI is 22 over 7!
If you try this program with PI and the first 10 digits of the remainder, you will see that 355 / 113 is acurate within 8 digits :-)
The natural base number is a little more difficult: 2.7182818284 = 2721 / 1001

Regards
   Michael c”.)
   
