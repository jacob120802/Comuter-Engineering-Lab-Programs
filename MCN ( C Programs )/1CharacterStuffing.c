#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

// Receiver: framed_data -> original data
int receiver()
{
    char framed_data[20], data[20];			
    int len, j = 0,flag=0,frame_length = 0;						// initially we do not know frame length, so set to 0

    printf("Enter the frame values: ");							// input values to be framed
    scanf("%s", framed_data);
    len = strlen(framed_data);									// total length of data

    for(i=0;i<len;i++)											// read through data
	{
        if(frame_length==0)										// if frame length is 0 -> prev frame is over; get length of next frame
        {
            frame_length =(int) (framed_data[i]-48);			// length of next frame-> convert char to int
            if(frame_length<=0 || frame_length>9)				// if frame length is not a number from 1 to 9 -> invalid message 
			{
				printf("Error in received message\n");
				flag=1;											// flag set to indicate error in message
				break;
			}
            frame_length--;										// decrement length
        }
        else
        {
            data[j++] = framed_data[i];							// original data extracted from framed data: remaining bits of frame put in original data
            frame_length--;										// decrement length
        }
    }
    data[j] = '\0';												// terminate string
    
    if(!flag)
    	printf("Original data: %s", data);						// print data if no error
    printf("\n\n");
}

// Sender: original data -> framed data
int sender()
{
    char framed_data[20] = "", data[20];
    int len, j = 0, s, fsize, total_frames;

    printf("Enter the data: ");							// input data
    scanf("%s", data);
    len = strlen(data);									// get length of data
    printf("Enter the frame size: ");
    scanf("%d", &fsize);								// fixed frame size method use: input frame size
    total_frames = (len / (fsize - 1));					// compute total frames: fsize-1 because 1 bit goes for storing len of frame
    for(i=0;i<=(len+total_frames);i++)					// length of framed data will be len + total frames (because no. of length bits present = total_frames)
    {
        if(i%fsize==0&&i!=(len+total_frames))			// if i is multiple of frame size then it is length bit
        {
            if ((len - j) < fsize)						// if remaining no. of characters < frame size
            {
                fsize = len - j + 1;					// get remaining no. of characters as frame size
            }
            framed_data[i] = (char)(48 + fsize);		// add frame size in framed data as char							
        }
        else
            framed_data[i] = data[j++];					// copy data in framed_data
    }

    printf("Data after Character count: %s", framed_data);		// print framed_data
    printf("\n\n");
}

int main()
{
    int c;														// menu driven code
    printf("%d", 'e');
	while (1)
    {
        printf("Menu:\n1. Transmitter\n2. Receiver\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            sender();
            break;
        case 2:
            receiver();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Enter valid choice.\n");
            break;
        }
    }
    return 0;
}
