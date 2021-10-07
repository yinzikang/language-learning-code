#include <stdio.h>
#include <string.h>
enum
{
    WAITING_FF1,//确定密码
    WAITING_FF2,//再次确定密码
    SENDER_ID,//看
    RECEIVER_ID,
    RECEIVE_LEN,
    RECEIVE_NAME,
    RECEIVE_SEX,
    RECEIVE_AGE,
    RECEIVE_INSTITUTION,
    RECEIVE_CHECK
}receive_state_;//调整机器状态

typedef struct
{
    char name[10];
    char sex[5];//01为男，02为女
    int age;
    int institution;
}information;

struct
{
    char sender_id;
    char receiver_id;
    int length;
    information student;
}Message;//相当于一条整的信息，发信人，收件人，长度，数据

void main()
{
    int key = 0;
    int check_num_ = 0;
    int  rx_data0_;//用于初步存储数据
    char rx_data1_[10];
    int  rx_data2_;
    Message.sender_id = 0x01;
    Message.receiver_id = 0x11;//填写收件人，发件人信息
    receive_state_ = WAITING_FF1;
    while(1)
    {
        if(key == 0) scanf("%x",&rx_data0_);
        else if(key == 1) scanf("%s",rx_data1_);
        else scanf("%d",&rx_data2_);

        switch(receive_state_)
        {
            case WAITING_FF1:
                if(rx_data0_ == 0xff)//两个0xff就相当于密码一样，只有连续输入两次才可以进入
                {
                    receive_state_ = WAITING_FF2;
                    check_num_ += rx_data0_;
                    printf("ok\n");
                }
                break;

            case WAITING_FF2:
                if(rx_data0_ == 0xff)
                {
                    receive_state_ = SENDER_ID;
                    check_num_ += rx_data0_;
                    printf("\nSENDER_ID: ");
                }
                break;

            case SENDER_ID:
                if(rx_data0_ == Message.sender_id)
                {
                    receive_state_ = RECEIVER_ID;
                    check_num_ += rx_data0_;
                    printf("\nRECEIVER_ID: ");
                }
                break;

            case RECEIVER_ID:
                if(rx_data0_ == Message.receiver_id)
                {
                    receive_state_ = RECEIVE_NAME;
                    check_num_ += rx_data0_;
                    printf("\nNAME: ");
                    key = 1;
                }
                break;

            case RECEIVE_NAME:
                strcpy(Message.student.name,rx_data1_);
                receive_state_ = RECEIVE_SEX;
                printf("\nSEX: ");
                break;

            case RECEIVE_SEX:
                strcpy(Message.student.sex,rx_data1_);
                receive_state_ = RECEIVE_AGE;
                key = 2;
                printf("\nAGE: ");
                break;

            case RECEIVE_AGE:
                Message.student.age = rx_data2_;
                check_num_ += rx_data2_;
                receive_state_ = RECEIVE_INSTITUTION;
                printf("\nINSTITUTION: ");
                break;

            case RECEIVE_INSTITUTION:
                Message.student.institution = rx_data2_;
                check_num_ += rx_data2_;
                receive_state_ = RECEIVE_CHECK;
                key = 0;
                printf("\nCHECK: ");
                break;

            case RECEIVE_CHECK:
                if(rx_data0_ == check_num_ % 255)
                {
                    printf("\nname: %s\n",Message.student.name);
                    printf("sex: %s\n",Message.student.sex);
                    printf("age: %d\n",Message.student.age);
                    printf("institution: %d\n",Message.student.institution);
                }
                receive_state_ = WAITING_FF1;
                key = check_num_ = 0;

          default:
                {
                    receive_state_ = WAITING_FF1;
                    key = check_num_ = 0;
                }
        }
    }
}
