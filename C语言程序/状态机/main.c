#include <stdio.h>
#include <string.h>
enum
{
    WAITING_FF1,
    WAITING_FF2,
    SENDER_ID,
    RECEIVER_ID,
    RECEIVE_LEN,
    RECEIVE_PACKAGE,
    RECEIVE_CHECK
}receive_state_;

struct
{
    unsigned char 		sender_id;
    unsigned char 		receiver_id;
    unsigned short int 	length;
    unsigned char 		data[120];
}Message;

int main()
{
    int i=0;
    int check_num_=0;
    unsigned int rx_data_;
    Message.sender_id=0x01;//16
    receive_state_ = WAITING_FF1;
    while(1)
    {
        scanf("%x",&rx_data_);
        switch(receive_state_)
        {
            case WAITING_FF1:
                if(rx_data_==0xef)
                {
                    receive_state_=WAITING_FF2;
                    check_num_+=rx_data_;
                    printf("ok\n");
                }
                break;

            case WAITING_FF2:
                if(rx_data_==0xff)
                {
                    receive_state_=SENDER_ID;
                    check_num_+=rx_data_;
                     printf("ok\n");
                }
                break;

            case SENDER_ID:
                if(rx_data_==Message.sender_id)
                {
                    i=0;
                    receive_state_=RECEIVE_LEN;
                    check_num_+=rx_data_;
                     printf("ok\n");
                }
                break;

            case RECEIVE_LEN:
                Message.length=rx_data_;
                receive_state_=RECEIVE_PACKAGE;
                check_num_+=rx_data_;
                 printf("ok\n");
                break;

            case RECEIVE_PACKAGE:
                Message.data[i]=rx_data_;
                i++;
                check_num_+=rx_data_;
                if(i==Message.length)
                    receive_state_=RECEIVE_CHECK;
                     printf("ok\n");
                break;
             case RECEIVE_CHECK:
                if(rx_data_==check_num_%256)
                {
                    i=0;
                    while(Message.data[i]!=0) {printf("%d ",Message.data[i]);i ++;}
                    printf("\nyou finished!!!\n");
                    check_num_ = 0;
                    receive_state_=WAITING_FF1;
                }
              default:
                receive_state_=WAITING_FF1;
        }
    }
    return 0;
}

