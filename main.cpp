#include <iostream>
#include <fstream>
#include <cstring>
#include <map>

using namespace std;


class product {
public:
    int cost;
    int count;


    virtual void Write(int fid, string ffirm, string fmodel, string fos, int fcost, string fname, string fmat, string fchargetype, int fcount) = 0;
    virtual void Print() = 0;

};

class smartphone : public product{
public:
    map<int, string> Firm;
    map<int, string> Model;
    map<int, string> Os;
    map<int, int> Cost;
    map<int, int> Count;


    void Write(int fid, string ffirm, string fmodel, string fos, int fcost, string fname, string fmat, string fchargetype, int fcount) override {

        Firm[fid] = ffirm;
        Model[fid] = fmodel;
        Os[fid] = fos;
        Cost[fid] = fcost;
        Count[fid] += fcount;


    }
    void Print() override {


        map <int,string>::iterator Ifirm;
        map <int,string>::iterator Imodel;
        map <int,string>::iterator Ios;
        map <int,int>::iterator Icost;
        map <int,int>::iterator Icount;

        Imodel=Model.begin();
        Ios=Os.begin();
        Icost=Cost.begin();
        Icount=Count.begin();


int mintime;

        for (Ifirm=Firm.begin();Ifirm!=Firm.end();Ifirm++)
        {
            if (Icount->second){
                cout<<" ID " << (*Ifirm).first<<" Марка "<<(*Ifirm).second<<  " Модель " << (*Imodel).second <<" Операционная система " <<(*Ios).second << " Стоимость " << (*Icost).second <<" Количество на складе " <<(*Icount).second<<endl;
            }
            Imodel++;
            Ios++;
            Icost++;
            Icount++;
        }



    }

};


class chehol : public product{
public:
    map<int, string> Name;
    map<int, string> Firm;
    map<int, string> Model;
    map<int, string> Mat;
    map<int, int> Cost;
    map<int, int> Count;


    void Write(int fid, string ffirm, string fmodel, string fos, int fcost, string fname, string fmat, string fchargetype, int fcount) override {
        Name[fid] = fname;
        Firm[fid] = ffirm;
        Model[fid] = fmodel;
        Mat[fid] = fmat;
        Cost[fid] = fcost;
        Count[fid] += fcount;


    }
    void Print() override {



        map <int,string>::iterator Iname;
        map <int,string>::iterator Ifirm;
        map <int,string>::iterator Imodel;
        map <int,string>::iterator Imat;
        map <int,int>::iterator Icost;
        map <int,int>::iterator Icount;

        Imodel=Model.begin();
        Iname=Name.begin();
        Icost=Cost.begin();
        Icount=Count.begin();
        Imat=Mat.begin();




        for (Ifirm=Firm.begin();Ifirm!=Firm.end();Ifirm++)
        {
            if (Icount->second){
                cout<<" ID " << (*Ifirm).first << " Название чехла " << (*Iname).second << " Марка "<<(*Ifirm).second<<  " Модель " << (*Imodel).second << " Материал " << (*Imat).second << " Стоимость " << (*Icost).second <<" Количество на складе " <<(*Icount).second<<endl;
            }
            Imodel++;
            Iname++;
            Icost++;
            Icount++;
            Imat++;

        }


    }

};


class charge : public product{
public:
    map<int, string> Name;
    map<int, string> Firm;
    multimap<int, string> Model;
    map<int, string> Chartype;
    map<int, int> Cost;
    map<int, int> Count;


    void Write(int fid, string ffirm, string fmodel, string fos, int fcost, string fname, string fmat, string fchargetype, int fcount) override {
        Name[fid] = fname;
        Firm[fid] = ffirm;
        Chartype[fid] = fchargetype;
        Cost[fid] = fcost;
        Count[fid] += fcount;


    }
    void WriteModel(int fid, string fmodel) {

        Model.insert( pair<int, string>(fid,fmodel));



    }
    void Print() override {



        map <int,string>::iterator Iname;
        map <int,string>::iterator Ifirm;
        multimap <int,string>::iterator Imodel;
        map <int,string>::iterator Ichartype;
        map <int,int>::iterator Icost;
        map <int,int>::iterator Icount;

        Imodel=Model.begin();
        Icost=Cost.begin();
        Icount=Count.begin();
        Ichartype=Chartype.begin();
        Iname=Name.begin();




        for (Ifirm=Firm.begin();Ifirm!=Firm.end();Ifirm++)
        {
            if (Icount->second){
                cout<<" ID " << (*Ifirm).first << " Название зарядки " << (*Iname).second << " Марка "<<(*Ifirm).second << " Тип зарядки " << (*Ichartype).second << " Стоимость " << (*Icost).second <<" Количество на складе " <<(*Icount).second;
                cout <<  " Совместимые модели  " ;
                for (Imodel = Model.begin(); Imodel != Model.end(); Imodel++)///вывод на экран
                {
                    cout << Imodel->second << " ";
                }
                cout << endl;
            }
            //Imodel++;
            Iname++;
            Icost++;
            Icount++;
            Ichartype++;

        }


    }

};


void findForSmart(){

}

struct korzina{
public:
    map<int, int> Count;
    map<int, string> Type;
    void Write(){

    }
    void Print() {

    }
};

int main()
{

    string fileName;
    int ftype;
    int fid;
    string ffirm;
    string fmodel;
    string fos;
    int fcost;
    string fname;
    string fmat;
    string fchargetype;
    int fcount;
    char zpt;


    cout <<"Введите имя и путь файла" <<endl;
    cin >> fileName;


    //введен заранее
    //fileName = "/home/hvendrix/file.txt";

    ifstream file;
    file.open(fileName);


    smartphone smart;
    chehol cheh;
    charge charg;
    korzina korz;

    while(file){
        if(file.is_open()){


            file>>ftype;
            if(ftype == 0){
                break;
            }

            file >> fid;

            switch(ftype){ //выбор категории товара
            case (1):{
                file >> ffirm >> fmodel>> fos >> fcost >> fcount;
                smart.Write(fid, ffirm, fmodel, fos, fcost, fname, fmat, fchargetype, fcount);
            }break;
            case(2):{
                file >> fname >> ffirm >> fmodel>> fmat >> fcost >> fcount;
                cheh.Write(fid, ffirm, fmodel, fos, fcost, fname, fmat, fchargetype, fcount);

            }break;
            case(3):{
                file >> fname >> ffirm >> fchargetype >> fcost >> fcount;
                charg.Write(fid, ffirm, fmodel, fos, fcost, fname, fmat, fchargetype, fcount);
                file>> fmodel >> zpt;
                charg.WriteModel(fid, fmodel);
                while (zpt == ','){
                    file >> fmodel;
                    charg.WriteModel(fid, fmodel);
                    file >> zpt;
                }
            }break;
            }



        }
    }


    while(true){
        int funName;
        cout << endl;
        cout << "1 - Показать все товары" << endl;
        cout << "2 - найти чехол для указанной модели" << endl;
        cout << "3 - найти зарядку для указанной модели" << endl;
        cout << "4 - добавить товар в корзину" << endl;
        cout << "5 - показать содержимое корзины" << endl;
        cout << "6 - добавить новый элемент" << endl;
        cin >> funName;

        switch(funName){
        case(1):{
            cout << endl << "Смартфоны:"<<endl;
            smart.Print();
            cout << endl << "Чехлы для смартфонов:"<<endl;
            cheh.Print();
            cout << endl << "Зарядки дял смартфонов:"<<endl;
            charg.Print();
        }break;
        case(2):{

            string mfind;
            cin >> mfind;

            for (int i = 1; i < 10; i++){
                if ((cheh.Model[i] == mfind) and cheh.Count[i]){
                    auto x = cheh.Name.begin();

                    cout <<"чехол для "<< mfind<< ": "<< x->second<< " " << i << " в наличие на складе: " << cheh.Count[i] << " штук(и)" <<endl;
                }
            }

        }break;
        case(3):{
            string mfind;
            cin >> mfind;

            //        for (int i = 1; i < 10; i++){
            //            auto p = charg.Model.begin();
            //            cout << p->second;


            for (auto i = charg.Model.begin(); i != charg.Model.end(); i++)
            {
                if ((i->second == mfind) and charg.Count[i->first]){
                    auto z = charg.Name[i->first];
                    cout <<"Зарядка для " << i->second << " " << z << " его ID " << i->first << " в наличие на складе: " << charg.Count[i->first] << " штук(и)" <<endl;;
                }
            }

        }break;

        case (4):{

            int uid;
            int ucount;
            string utype;
            uid =0;
            ucount =0;
            utype = "";
            int ucheck;
            ucheck = 0;

            cout << "Введите ID"<< endl;
            cin >> uid;

            cout << "Введите кол-во" << endl;
            cin >> ucount;
            if (ucount>=0){
                if ((smart.Count[uid]) and (smart.Count[uid] >= ucount)){
                    smart.Count[uid] -= ucount;
                    korz.Count[uid] += ucount;
                    utype = "tsmart";
                    korz.Type.insert (pair <int, string> (uid, utype));
                    ucheck++;
                }
                if ((cheh.Count[uid]) and (cheh.Count[uid] >= ucount)){
                    cheh.Count[uid] -= ucount;
                    korz.Count[uid] += ucount;
                    utype = "tcheh";
                    korz.Type.insert (pair <int, string> (uid, utype));
                    ucheck++;
                }
                if ((charg.Count[uid]) and (charg.Count[uid] >= ucount)){
                    charg.Count[uid] -= ucount;
                    korz.Count[uid] += ucount;
                    utype = "tcharg";
                    korz.Type.insert (pair <int, string> (uid, utype));
                    ucheck++;
                }
            }else cout << "Вы ввели неправильное число"<<endl;
if (!ucheck){
    cout << "Вы ввели неправильное число"<<endl;
}

        } break;

        case (5):{
            map <int,int>::iterator Icount;
            map <int,string>::iterator Itype;
            Itype=korz.Type.begin();
            cout << "Ваша корзина:"<<endl;
            for (Icount=korz.Count.begin();Icount!=korz.Count.end();Icount++){
                cout << "ID " <<Icount->first << " количество " << Icount->second << " тип товара " << Itype->second <<endl;
                Itype++;
            }
        }break;
        case (6):{
            int usrtype;

            int usrid;
            string usrfirm;
            string usrmodel;
            string usros;
            int usrcost;
            string usrname;
            string usrmat;
            string usrchargetype;
            int usrcount;
            char usrzpt;

            cout <<"Введите тип товара (1 - смартфон, 2 - чехол, 3 - зарядка):" <<endl;
            cin >> usrtype;
            cout <<"Введите ID:" <<endl;
            cin >> usrid;
            switch(usrtype){
            case (1):{
                cin >> usrfirm >> usrmodel>> usros >> usrcost >> usrcount;
                smart.Write(usrid, usrfirm, usrmodel, usros, usrcost, usrname, usrmat, usrchargetype, usrcount);
            }break;
            case(2):{
                cin >> usrname >> usrfirm >> usrmodel>> usrmat >> usrcost >> usrcount;
                cheh.Write(usrid, usrfirm, usrmodel, usros, usrcost, usrname, usrmat, usrchargetype, usrcount);
            }break;
            case(3):{
                cin >> usrname >> usrfirm >> usrchargetype >> usrcost >> usrcount;
                charg.Write(usrid, usrfirm, usrmodel, usros, usrcost, usrname, usrmat, usrchargetype, usrcount);
                cin>> usrmodel >> usrzpt;
                charg.WriteModel(usrid, usrmodel);
                while (usrzpt == ','){
                    cin >> usrmodel;
                    charg.WriteModel(usrid, usrmodel);
                    cin >> usrzpt;
                }
            }
            }


        }

        }
    }


    file.close();





    return 0;
}
