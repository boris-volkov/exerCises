#include <stdio.h>

int main()
{
	int   a  =  0b1000001; // binary65
	char  b  =  0b1000001; 
	printf("int %d\n", a);
	printf("chr %c\n", b);
	a++; // both can be incremented
	b++; // since both are just numbers
	printf("add 1 to both\n");
	printf("int %d\n", a);
	printf("chr %c\n", b);
}
//*
//
// There is no such thing as different kinds of
// objects in a computer program.
// It is all just binary, and instructions, which
// are aslo binary. 
//
// This is important because computer students
// will begin by learning about all sorts of
// different kinds of objects. strings, ints, 
// chars, arrays, lists, linked lists, trees, 
// graphs, heaps, stacks, etc. All of these things
// are spoken of as if they are made out of
// different stuff inside the computer. But they
// are only made out of binary sequences.
//
// 1000001
//
// Do you know what this binary sequence means?
// If you said 65, good! But wait, I did not say
// that this was a number. What if I was referring
// to it as a letter (char in the computer language)
// if I read it as a letter, it would be the
// letter A. So then what is it? By itself it is
// nothing. It is just a piece of code, and we have
// to tell the computer how do decode it.
//
// It has to be told in advance, that when it is 
// fed in 1000001 as an int object, then treat it
// like the number 65. If, instead, it is fed in
// 1000001 as a char object, it will treat it like
// the letter A.
//
// So how do you tell the computer how to read it?
// You first feed the binary into an object.
// Objects are like dressing your twins in
// different colors to help tell them apart. 
//
// Underneath it's all the same binary, but the 
// computer dresses it up with all of the 
// functionality we expect from the type of thing
// it is. If it is an int, we expect to be able 
// to divide by it, and even to return an error
// if we try to divide by zero. If it is a letter
// we would like to be able to decapitalize it,
// for example. The full functionality of these
// simple objects is quite wide, sort of like how
// the simplest words in dictionaries often have
// the longest entries. 
//
// So when this program runs, these same binary
// sequences are dressed up differently. 
// One of them is named a, and as soon as he is
// born, is promoted to an integer, given all 
// the tools for the job, given the full
// certification, the seal of authenticity. 
//
// The other is turned into a "character" in a
// similar manner, and sent off to work - in this
// program to make an appearance on the screen.
// alongside his old twin, who now looks quite
// different. 
//
// Now, I wouldn't be going so far into this
// if it wasn't for how difficult it is to see
// this early on. 
//
// When I would watch coding tutorials and was
// typing code like  
//  	a = 65
//  	b = 'A'
// The thought would not have crossed my mind,
// that they are represented by the same code.
// And I appreciate how it simplifies my work.
// It would obviously be a pain to have to type
// in binary codes for everything, and nobody
// is expected to do that. But for the sake of
// understanding what is really happening in the
// computer can quite surprisingly make things
// simpler. 
//
// It changed the computer from a realm of
// threatening, unknown objects into a much more
// familiar place. 
//
// The "Structures" (structs, objects), are just
// instructions on where to move pointers. 
//
