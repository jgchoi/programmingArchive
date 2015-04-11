/*
 * Name             : Jung Geon Choi
 * Student Number   : 025651134
 * Due Date         : Jan. 19, 2014
 * Course Code      : BTI220
 * Program Name     : Calculator
 * Problem          : Code calculator using Javascript. The calculator should have validation for correct input.
 8                    Calculator should prompt user to input 2 numbers with performance (+,-.*,/). Program will repeat until user input 0.
 */

/*
 * I declare that the attached assignment is wholly my own work in 
 * accordance with Seneca Academic Policy. No part of this assignment has 
 * been copied manually or electronically from any other source (including 
 * web sites) or distributed to other students.
 * Name ___Jung Geon Choi____________________ Student ID _025651134______
 */


    //valuable
        f=0;   // global valuable to stop program if user input 0 at any time.
    var x;     // first num
    var y;     // second num
    var p;     // performance
    
    while(f==0)
     {
        (alert("Calculator:\n\n\tInput First number, performance, and second number.\n\n\tInput 0 at any time to finish the program. "));
        
        x=numIn("First"); //first number input
        if(f==1)break;
        x=Number(x); // change string to number for calculation
        
        p=perIn(); // performance input
        if(f==1)break;
        
        y=numIn("Second"); //sec. number input
        if(f==1)break;
        y=Number(y);
        
        //based on performance user input, performing calculation
        switch(p)
        {
        case 0 :
            (alert( x + " + " + y + " = " + (x+y)));break;
        case 1 :
            (alert( x + " - " + y + " = " + (x-y)));break;
        case 2 :
            (alert( x + " / " + y + " = " + (x/y)));break;
        case 3 :
            (alert( x + " * " + y + " = " + (x*y)));break;
        }
     }//end of while, if user input 0
    alert("Thank you! Have a Nice Day~");


//function to take number input and validation
function numIn(seq)//"seq" parameter is string that goes into the msg box first, second..
{
var i;
var j=0;

while(j==0)
{
i=prompt("Input " + seq + " Number");
i=parseFloat(i); //if possible type error, only filter out numbers
if(i=="0")
     {f=1; //if 0, program end
      j=1; //if 1, loop end
     };
if(isNaN(i)==true) //not a number
    alert("NUMBER..please..");
if(isNaN(i)==false)//all good
    j=1;

}
return i;

}



function perIn()
{
var i;
var j=0;
while(j==0)
{
i=prompt("Choose performance (+,-,*,/)");
if(i=="0"){
    f=1;break;}
if(isNaN(i)==false) //if user input 0~3 .. no good
i=4;
else
{
switch(i)
    {
    case "+" :
        return 0;
    case "-" :
        return 1;
    case "/" :
        return 2;
    case "*" :
        return 3;
    }
}
if(i>=0 && i<=3)
j=1;
else
alert("+ - * /");
}
}