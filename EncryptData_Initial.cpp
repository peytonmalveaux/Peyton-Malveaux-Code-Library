// EncryptData.cpp
//
// This file uses the input data and key information to encrypt the input data
//

#include "Main.h"
#define LOOP

// YOU WILL DELETE ALL THIS CODE WHEN YOU DO YOUR PROJECT - THIS IS GIVING YOU EXAMPLES OF HOW TO 
// ACCESS gPasswordHash AND gKey

void encryptData_01(char *data, int datalength)
{
	//int idx;  //index
	int hop0;
	int curRound = 0;

	__asm
	{
BIG_LOOP:
		
		lea esi, gPasswordHash

		xor ecx, ecx// zero out the count register for the loop, and used for data
		xor eax, eax// using eax for the key
		xor ebx, ebx

		mov ebx, curRound

		// Index:
		mov ah, byte ptr[esi + ebx * 4]
		mov al, byte ptr[esi + ebx * 4 + 1]
		//index would be eqaul to ax

		//Hop Count:
		xor edx, edx
		mov dh, byte ptr[2 + esi + ebx * 4]
		mov dl, byte ptr[3+esi+ebx*4]
		cmp edx, 0
		jne HERE
		mov edx, 0xFFFF
			
		HERE:
		mov hop0, edx
		xor edx, edx
		//edx is free
		xor ebx, ebx
		mov edi, data
		xor ecx,ecx
	LOOP_START:

			mov bl, byte ptr[gkey + eax] // gets 1 byte of key set
			mov dl, byte ptr[ecx + edi]   // gets 1 byte of data set
			xor dl, bl //perform the xor on the two data sets
			//put data back from dl 
			mov byte ptr[ecx + edi], dl  //<-- correct

			//EAX is Starting Index, ECX is Hop Count
			add eax, hop0 // [ebp-4]
			cmp eax, 65537
			jl DO_NOTHING
			sub eax, 65537d

		DO_NOTHING:
			//Step E - rotate 2 bits to the right:

			ror dl, 2	//<-- correct

			//D: Invert them bits
			// invert bx:0,2,4,7
			xor dl, 0x95	//<-
					//- correct

			//C: Reverse Bit Order
			mov esi, 8
			RVSLoop :

			    shr dl, 1
				rcl bh, 1
				dec esi
				jnz RVSLoop	//<-- looks correct

				xor edx, edx
				mov dl, bh

				//A:code table swap
				mov bl, byte ptr[gEncodeTable + edx]		//<-- can't zero extend into a byte, no compile error on this??
															//<-- need to see your crypto main and main.h file to make sure this is correct
				//B: nibble rotate out
				xor bh, bh
				
				// data is in bl
				
				clc
				mov dl, bl // abcd efgh
				mov dh, bl //tmp
				and dh, 0x80 // a000 0000
				shr dh, 3 //000a 0000
				and dl, 0xF0 //abcd 0000
				shl dl, 1 //bcd0 0000
				or dl, dh //bcda 0000

				xor dh, dh

				mov bh, bl
				and bh, 0x0f //--bh = 0000 efgh
				mov dh, bh // dh = 0000 efgh
				shr dh, 1 // dh = 0000 0efg
				and bh, 0x01 // bh = 0000 000h
				shl bh, 3 // 0000 h000
				add dh, bh // == 0000 hefg

				// dl and dh hold the two nibbles
				or dl, dh // bcda0000 + 0000hefg = bcda hefg
			
				mov byte ptr[ecx + edi], dl		//<-- looks correct
				//Increment the count register ENDING
				inc ecx

				cmp ecx, datalength
				jl LOOP_START// to determine when to end the for loop
			
			xor ebx, ebx
			inc curRound
			mov ebx, curRound 
			cmp ebx, gNumRounds
			jl BIG_LOOP
	}

	return;
} // encryptData_01

//////////////////////////////////////////////////////////////////////////////////////////////////
// EXAMPLE code to to show how to access global variables
int encryptData(char *data, int dataLength)
{
	int resulti = 0;

	gdebug1 = 0;				// a couple of global variables that could be used for debugging
	gdebug2 = 0;				// also can have a breakpoint in C code

	// You can not declare any local variables in C, but should use resulti to indicate any errors
	// access the parameters BEFORE setting up your own stack frame
	//-------------------------------------------GROUP CODE-------------------------------------//
/*
	__asm {
		// you will need to reference some of these global variables
		// (gptrPasswordHash or gPasswordHash), (gptrKey or gkey), gNumRounds

		// simple example that xors 2nd byte of data with 14th byte in the key file
		lea esi,gkey				// put the ADDRESS of gkey into esi
		mov esi,gptrKey;			// put the ADDRESS of gkey into esi (since *gptrKey = gkey)

		lea	esi,gPasswordHash		// put ADDRESS of gPasswordHash into esi
		mov esi,gptrPasswordHash	// put ADDRESS of gPasswordHash into esi (since unsigned char *gptrPasswordHash = gPasswordHash)

		mov al,byte ptr [esi]				// get first byte of password hash
		mov al,byte ptr [esi+4]				// get 5th byte of password hash
		mov ebx,2
		mov al,byte ptr [esi+ebx]			// get 3rd byte of password hash
		mov al,byte ptr [esi+ebx*2]			// get 5th byte of password hash

		mov ax,word ptr [esi+ebx*2]			// gets 5th and 6th bytes of password hash ( gPasswordHash[4] and gPasswordHash[5] ) into ax
		mov eax,dword ptr [esi+ebx*2]		// gets 4 bytes, as in:  unsigned int X = *( (unsigned int*) &gPasswordHash[4] );

		mov al,byte ptr [gkey+ebx]			// get's 3rd byte of gkey[] data

		mov al,byte ptr [gptrKey+ebx]		// THIS IS INCORRECT - will add the address of the gptrKey global variable (NOT the value that gptrKey holds)

		mov al,byte ptr [esi+0xd];			// access 14th byte in gkey[]: 0, 1, 2 ... d is the 14th byte
		mov edi,data				// Put ADDRESS of first data element into edi
		xor byte ptr [edi+1],al		// Exclusive-or the 2nd byte of data with the 14th element of the keyfile
									// NOTE: Keyfile[14] = 0x21, that value changes the case of a letter and flips the LSB
									// Capital "B" = 0x42 becomes lowercase "c" since 0x42 xor 0x21 = 0x63
	}
	*/
	return resulti;
} // encryptData

