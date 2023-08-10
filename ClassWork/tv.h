#ifndef TV_H_
#define TV_H_
#pragma("")
//class Remote;  // предварительное объявление класса для дружственной функции 

class Tv
{
private:
	int state;             // On или Off 
	int volume;            // уровни громкости 
	int maxchannel;        // максимальное количество каналов 
	int channel;           // текущий канал 
	int mode;              // эфирное или кабельное телевидение 
	int input;             // TV или DVD

public:
    friend class Remote;   // Remote имеет доступ к закрытой части Тѵ 

    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125) : state(s), 
                                    volume(5),
                                    maxchannel(mc), channel(2), 
									mode(Cable), input(TV) {   }

    void onoff() {state = (state == On)? Off : On;}   
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
    void set_input() {input = (input == TV)? DVD : TV;}
    void settings() const;    // отображение всех настроек 

	// Вариант 2: класс Remote - не друг класса Tv
    //friend void set_chan(Tv & t, const Remote & r, int c);
	
};


//-------------------------------------------------------------------
class Remote
{
private:
    int mode;              // управление TV или DVD 
public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }

	// Вариант 1: класс Remote - друг класса Tv
    void set_chan(Tv & t, int c) {t.channel = c;}     
	// доступ к закрытому полю класса Tv в случае дружественного класса
	   	

	// Вариант 2: класс Remote - не друг класса Tv
	//friend void set_chan(Tv & t, const Remote & r, int c) { t.channel = c; }
    
};

#endif


//-------------------------------------------------------------------

// В случае не предоставления классу дружбы надо:

// 1. сделать предварительное объявление класса
//class Remote;  // предварительное объявление класса для дружственной функции 

//2. В классе Tv объявить др. функцию
//friend void set_chan(Tv & t,  const Remote & r,  int c);	

//3. В классе Remote объявить и реализовать др. функцию
//friend void set_chan( Tv & t,  const Remote & r,  int c) {t.channel = c;}    
// доступ к закрытому полю channel класса Tv
