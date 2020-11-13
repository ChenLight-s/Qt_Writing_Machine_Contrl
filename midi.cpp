#include "midi.h"






struct midi2mus
{
    int time;
    int flag;
    int note;
    float msnote;
    float octave;
    float soundLength;
};

void  midi2Music(QString str)
{
    QString temp;
    QString stemp1 = "1a0b2cd3";
    midi2mus midi2mus;
    int temp1 =0;
    bool ok =true;
    qDebug()<<"长度："<<str.size();
//    qDebug()<<"内容："<<str;
//    str = str.right(str.size()/4);
//    if(str.contains("81368047"))
//    {
//        str = str.left(str.size()-str.indexOf("81368047"));
//        qDebug()<<"内容："<<str;
//        qDebug()<<"长度："<<str.size();
//    }
    for (int i=0; str.size()>7;i++) {

//        for(int n =0; n<4;n++){
//            temp  += str.left(2);
//            midi2mus.time =str.left(2).toInt(&ok,16);
//            midi2mus.flag =str.left(2).toInt(&ok,16);
//            temp += QString::number(midi2mus.flag);
//            str = str.right(str.size()-2);
//            qDebug()<<"midi2mus.time ="<<midi2mus.time;
//            temp += QString::number(midi2mus.time);
//            temp += ",";
            str = str.right(str.size()-2);
            midi2mus.note =str.left(2).toInt(&ok,16) +1;
//            midi2mus.flag =str.left(2).toInt(&ok,16);
//            temp += QString::number(midi2mus.note);
//            temp += ",";
            str = str.right(str.size()-4);
            midi2mus.time =str.left(2).toInt(&ok,16);
            if(midi2mus.time >127)
            {
                midi2mus.time = (midi2mus.time -0x80) *128;
//                qDebug()<<"midi2mus.time1 ="<<midi2mus.time;
                str = str.right(str.size()-2);
//                qDebug()<<"midi2mus.time2 ="<<str.left(2).toInt(&ok,16);
                midi2mus.time += str.left(2).toInt(&ok,16);
            }
//            qDebug()<<"midi2mus.time ="<<midi2mus.time;
            temp += QString::number(midi2mus.time);
            temp += ",";
//            midi2mus.note =str.left(2).toInt(&ok,16);
//            qDebug()<<"midi2mus.note ="<<midi2mus.note;
//            midi2mus.flag =(str+6).left(2).toInt(&ok,16);
            switch ((midi2mus.note) %12) {
            case 0:
                midi2mus.msnote= 1;
                break;
            case 1:
                midi2mus.msnote= 1.5;
                break;
            case 2:
                midi2mus.msnote= 2;
                break;
            case 3:
                midi2mus.msnote=2.5;
                break;
            case 4:
                midi2mus.msnote=3;
                break;
            case 5:
                midi2mus.msnote=4;
                break;
            case 6:
                midi2mus.msnote=4.5;
                break;
            case 7:
                midi2mus.msnote=5;
                break;
            case 8:
                midi2mus.msnote=5.5;
                break;
            case 9:
                midi2mus.msnote=6;
                break;
            case 10:
                midi2mus.msnote=6.5;
                break;
            case 11:
                midi2mus.msnote=7;
                break;
            }
//            midi2mus.msnote = midi2mus.note % 12;
            temp += QString::number(midi2mus.msnote);
//            qDebug()<<midi2mus.msnote <<" ";
            temp += ",";
            midi2mus.octave = midi2mus.note /12 -1;
            temp += QString::number(midi2mus.octave);
            temp += ",";
//            if(midi2mus.time == 129)
//            {
//                qDebug()<<"i ="<<i;
//                break;
//            }

//            temp1 = str.left(2).toInt(&ok,16);
//            qDebug()<<"temp1=" <<temp1;
//            temp += QString::number(temp1);
//            temp += ",";
            str = str.right(str.size()-2);
//            qDebug()<<"37\r\n";
//        }

//        qDebug()<<"长度："<<str.size();
        qDebug()<<"temp=" <<temp;
        temp.clear();
    }

}
void midi(QString content)
{
//    qDebug()<<content;
    int num = 0;
    int temp1 =0;
    bool ok  =true;
    qDebug()<<content.indexOf("3d546864");
    QString temp;
//    qDebug()<<content.toUInt();
    //判断是否包含文件头 MThd
    if(content.contains("4d546864"))
    {
        num = 4*2;
        num =6*2;
        content = content.right(content.size()-num);
        qDebug()<<content;
        num =4;
        //数据长度
        temp = content.left(num);
        temp1 = temp.toUtf8().toInt();
//        qDebug()<<"temp1="<<temp1;
        qDebug()<<"数据长度="<<temp;
        content = content.right(content.size()-num);
        //Midi格式 0000 单音轨  0001 多音轨  0002其他
        temp = content.left(num);
//        qDebug()<<"temp="<<temp;
        temp1 = temp.toUtf8().toInt();
        qDebug()<<"音轨，1为多音轨="<<temp1;
        content = content.right(content.size()-num);
        //音轨 = 实际音轨个数 +1
        temp = content.left(num);
        qDebug()<<"temp="<<temp;
        temp1 = temp.toUtf8().toInt();
        qDebug()<<"音轨="<<temp1-1;
        content = content.right(content.size()-num);

        //节拍时间 即歌曲为 dddd拍/分钟
        temp = content.left(num);
        qDebug()<<"temp="<<temp;
        temp1 = temp.toInt(&ok,16);
        qDebug()<<"节拍="<<temp1;
        content = content.right(content.size()-num);
        if(content.contains("4d54726b"))
        {
            num = content.indexOf("4d54726b");
            num += 4*2;
            content = content.right(content.size()-num);
//            qDebug()<<content;
        }
        if(content.contains("4d54726b"))
        {
            num = content.indexOf("4d54726b");
            num += 4*2;
            content = content.right(content.size()-num);
//            qDebug()<<content;
        }
        if(content.contains("547261636b"))
        {
            num = content.indexOf("547261636b");
            num += 5*2;
            num += 3*2;//
            //获得谱子
            content = content.right(content.size()-num);

//            qDebug()<<content;
        }

        //开始解析谱子
        midi2Music(content);
//        num = 4;

//        //节拍时间 即歌曲为 dddd拍/分钟
//        temp = content.left(num);
//        qDebug()<<"temp="<<temp;
//        temp1 = temp.toInt(ok,16);
//        qDebug()<<"temp1="<<temp1;
//        content = content.right(content.size()-num);
        //

    }
    else {
        qDebug()<<"输入的非MIDI文件，请重新输入";
    }
}





























