class Character{
private:
    std::string name;   // Basic Information
    std::string type;
    std::string classs;
    int age;
    int I;          // Intelligence
    int C;          // Charisma
    int M;          // Mischief
    int MF;         // Mental Fortitude
    int T;          // Toughness
    int A;          // Agility
public:
    Character(std::string n, int a):name(n), age(a){}
    void display(){
        std::cout << "Character Information" << std::endl;
        std::cout << "Name:   " << name << std::endl;
        std::cout << "Age:    " << age << std::endl;
        std::cout << "Race:   " << type << std::endl;
        std::cout << "Class:  " << classs << std::endl;
        std::cout << "Attributes: " << std::endl;
        std::cout << "\tIntelligence:     " << I << std::endl;
        std::cout << "\tCharisma:         " << C << std::endl;
        std::cout << "\tMischief:         " << M << std::endl;
        std::cout << "\tMental Fortitude: " << MF << std::endl;
        std::cout << "\tToughness:        " << T << std::endl;
        std::cout << "\tAgility:          " << A << std::endl;
        std::cout << "\nShort Description: " << std::endl;
        std::cout << description << std::endl;
    }
    void setAttributes(int i, int c, int m, int mf, int t, int a, std::string z) {
        I = i; C = c; M = m;
        MF = mf; T = t; A = a;
        type = z;
    }
    std::string description;
    std::string getType() {return type;}
    void setClasss(std::string c) {classs = c;}
    void setI(int i){I = i;}
    void setC(int c){C = c;}
    void setM(int m){M = m;}
    void setMF(int mf){MF = mf;}
    void setT(int t){T = t;}
    void setA(int a){A = a;}

    int getI(){return I;}
    int getC(){return C;}
    int getM(){return M;}
    int getMF(){return MF;}
    int getT(){return T;}
    int getA(){return A;}
};

/*=========================================================================*/

Character charCreation(){
    Begin:
    std::cout << "Welcome to the Fantasy Adventure Game (working title)" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "Press [1] to create your character." << std::endl;
    int b;
    std::cin >> b;
    if(b != 1) {std::cout << "Try again!"; goto Begin;}
    std::cout << "Name: " << std::endl;
    std::string n;
    std::cin >> n;
    std::cout << "Age:  " << std::endl;
    int a;
    std::cin >> a;
    Retry:
    std::cout << "========================" << std::endl;
    std::cout << "Race of Character: " << std::endl;
    std::cout << "\t[1] Human" << std::endl;
    std::cout << "\t[2] Dwarf" << std::endl;
    std::cout << "\t[3] Elf" << std::endl;
    std::cout << "\t[4] Giant" <<std::endl;
    std::cout << "\t[5] Hobgoblin" << std::endl;
    std::cout << "========================" << std::endl;
    int j;
    std::cin >> j;
    Character p(n, a);
    switch(j){
        case(1):
            p.setAttributes(5,5,5,5,5,5,"Human");
            p.description = "Well rounded, but average in all things.";
            break;
        case(2):
            p.setAttributes(7,9,2,6,6,0,"Dwarf");
            p.description = "Intelligent engineers, their height damages their agility.";
            break;
        case(3):
            p.setAttributes(9,3,1,7,4,6,"Elf");
            p.description = "Wise, noble and pure. Not that fun to be around though.";
            break;
        case(4):
            p.setAttributes(0,3,6,8,10,3,"Giant");
            p.description = "Tough, mentally strong because of their stupidity - dumb as a rock.";
            break;
        case(5):
            p.setAttributes(4,1,10,4,3,8,"Hobgoblin");
            p.description = "Mischievous and agile. Weak and frail.";
            break;
    }
    p.display();
    std::cout << "Confirm? Y/N" << std::endl;
    char input;
    std::cin >> input;
    if(input == 'Y' || input == 'y'){
        system("CLS");
    } else {
        system("CLS");
        goto Retry;
    }
    Again:
    std::cout << "===============================================" << std::endl;
    std::cout << "Now select a class for your " << p.getType() << " character." << std::endl;
    std::cout << "Types of Classes: " << std::endl;
    std::cout << "\t[1] Warrior" << std::endl;
    std::cout << "\t[2] Archer" << std::endl;
    std::cout << "\t[3] Tank" << std::endl;
    std::cout << "\t[4] Mage" <<std::endl;
    std::cout << "\t[5] Thief" << std::endl;
    std::cout << "\t[6] Vampire" << std::endl;
    std::cout << "========================" << std::endl;
    int i;
    std::cin >> i;
    switch(i){
    case(1):
        std::cout << "You are a warrior. +2 toughness - your armor slows you down however, -2 agility." << std::endl;
        std::cout << "Are you sure you want to be a warrior? [Y/N]" << std::endl;
        char go;
        std::cin >> go;
        if(go == 'Y'||go == 'y'){
            system("CLS");
            p.setClasss("Warrior");
            p.setT(p.getT()+2); p.setA(p.getA()-2);
        } else {
            system("CLS");
            goto Again;
        }
        break;
    case(2):
        std::cout << "You are an archer. +1 agility and +1 mental fortitude, but -3 toughness." << std::endl;
        std::cout << "Are you sure you want to be an archer? [Y/N]" << std::endl;
        char goo;
        std::cin >> goo;
        if(goo == 'Y'||goo == 'y'){
            system("CLS");
            p.setClasss("Archer");
            p.setT(p.getT()-3); p.setA(p.getA()+1); p.setMF(p.getMF()+1);
        } else {
            system("CLS");
            goto Again;
        }
        break;
    case(3):
        std::cout << "You are a tank. +3 toughness, but -2 agility." << std::endl;
        std::cout << "Are you sure you want to be a tank? [Y/N]" << std::endl;
        char gooo;
        std::cin >> gooo;
        if(gooo == 'Y'||gooo =='y'){
            system("CLS");
            p.setClasss("Tank");
            p.setT(p.getT()+3); p.setA(p.getA()-2);
        } else {
            system("CLS");
            goto Again;
        }
        break;
    case(4):
        std::cout << "You are a mage. +3 intelligence, but -3 toughness." <<std::endl;
        std::cout << "Are you sure you want to be a mage? [Y/N]" << std::endl;
        char goooo;
        std::cin >> goooo;
        if(goooo == 'Y'||goooo =='y'){
            system("CLS");
            p.setClasss("Mage");
            p.setI(p.getI()+3); p.setT(p.getT()-3);
        } else {
            system("CLS");
            goto Again;
        }
        break;
    case(5):
        std::cout << "You are a thief. +2 mischief, +1 agility. But -3 intelligence." << std::endl;
        std::cout << "Are you sure you want to be a thief? [Y/N]" << std::endl;
        char gooooo;
        std::cin >> gooooo;
        if(gooooo == 'Y'||gooooo =='y'){
            system("CLS");
            p.setClasss("Thief");
            p.setM(p.getM()+2); p.setA(p.getA()+1); p.setI(p.getI()-3);
        } else {
            system("CLS");
            goto Again;
        }
        break;
    case(6):
        std::cout << "You are a vampire. +2 charisma, but -1 mental fortitude." << std::endl;
        std::cout << "Are you sure you want to be a vampire? [Y/N]" << std::endl;
        char goooooo;
        std::cin >> goooooo;
        if(goooooo == 'Y'||goooooo == 'y'){
            system("CLS");
            p.setClasss("Vampire");
            p.setC(p.getC()+2); p.setMF(p.getMF()-1);
        } else {
            system("CLS");
            goto Again;
        }
        break;
    }
    std::cout << "This is your character: " << std::endl;
    p.display();
    Agaiin:
    std::cout << "Press [2] to continue and start your adventure!" << std::endl;
    int c;
    std::cin >> c;
    if(c != 2){std::cout << "Try Again!" << std::endl; goto Agaiin;}
    system("CLS");
    std::cout << "You walk along a path for miles, until you see the path split in 2, the left path\n";
    std::cout << "leads into a forest, while the right path goes into a nearby town.\n";
    CBA:
    std::cout << "Which path do you follow? [1] - Forest || [2] - Town" << std::endl;
    int d;
    std::cin >> d;
    switch(d){
        case(1):
            std::cout << "You wander along the forest and find a witches hut. She sees you and demands you fight\n";
            std::cout << "to the death.\n";
            std::cout << "==============================\n";
            std::cout << "6+ toughness beats the which instantly, 3 - 5 toughness is a 50/50 shot. Anything below 3 - you're dead." << std::endl;
            std::cout << " Remember, your toughness is " << p.getT() << "." << std::endl;
            std::cout << "Do you fight? Yes [1] No [0]" << std::endl;
            int e;
            std::cin >> e;
            switch(e){
                case(1):
                    if(p.getT() >= 6) {
                        std::cout << "The which dies a brutal death. You find her books and read them, +2 intelligence.\n";
                        p.setI(p.getI()+2);
                    } else if(p.getT() >= 3 && p.getT() < 6) {
                        int raate = rand() % 100 + 1;
                        if(raate >= 50){
                            std::cout << "You narrowly beat the which. Reading her potion books gives you +2 intelligence.\n";
                            std::cout << "At the end of the forest you see a clearing... you head towards it.\n";
                            p.setI(p.getI()+2);
                        } else {
                            std::cout << "The which has bested you. You are dead. Game over." << std::endl;
                        }
                    }
                break;
                case(0):
                    std::cout << "Attempting to flee..." << std::endl;
                    int rate = rand() % 100 + 1;
                    if(rate <= 50) {
                        std::cout << "You have failed to run away. The witch kills you." << std::endl;
                        goto END;
                    } else {
                        std::cout << "You narrowly escape with your life." << std::endl;
                        std::cout << "At the end of the forest you see a clearing... you head towards it." << std::endl;
                    }
                break;
            }
            break;
        case(2):
            std::cout << "You enter the town and see a merchant selling some armor. If you could buy it\n";
            std::cout << "you would get a +2 increase to your toughness. The thing is though, you have no money.\n";
            std::cout << "You could try to persuade him to give it to you for free but you need to be very smart\n";
            std::cout << "(intelligence 7+) and be able to endure a long debate (mental fortitude 5+).... OR, you could\n";
            std::cout << "wait until he is not looking and steal it. Note that if you are a thief you automatically do this\n";
            std::cout << "all other classes need at least (mischief 5+ - 75% chance, 3 to 5 is a 50/50, below a 3, and you\n";
            std::cout << "can't steal." << std::endl;
            std::cout << "Remember:\nYour mischief: " << p.getM() << ".\nYour Intelligence: " << p.getI() <<
            ".\nYour Mental Fortitude: " << p.getMF() << ".";
            std::cout << "\n\nWhat do you do? Bargain - [1] || Steal - [2]\n";
            int f;
            std::cin >> f;
            switch(f){
            case(1):
                if(p.getI() >= 7 && p.getMF() >= 5){
                    std::cout << "You manage to convince him to give you the armor. +2 toughness.\n";
                    std::cout << "You exit the town and see a clearing in the distance, you make your way towards it.\n";
                }
            break;
            case(2):
                if(p.getType() == "Thief"){std::cout << "You are a thief, so you easily steal the armor. +2 toughness.\n";}
                else if (p.getM() >= 5){
                    int rate = rand() % 100 + 1;
                    if(rate >= 25){std::cout << "You managed to steal it - +2 toughness.\n";}
                }else if (p.getM() > 2 && p.getM() < 6){
                    int rate = rand() % 100 + 1;
                    if(rate >= 50){std::cout << "You managed to steal it - +2 toughness.\n";}
                } else {
                    std::cout << "You could not manage to steal it. Theft is punishable by death here. Game over.\n";
                }
                std::cout << "You see a clearing at the end of the town, you head towards it.\n";
                break;
            }
            break;
        default:
            std::cout << "Enter a number please." << std::endl;
            system("CLS");
            goto CBA;
            break;
    }
    std::cout << "Well that was pretty fun. Continue? Y/N" << std::endl;
    char z;
    std::cin >> z;
    if(z == 'Y' || z == 'y'){
        system("CLS");
    } else {
        goto GO;
    }
    std::cout << "At the clearing you see the princess this game is about, evidently. She is being attacked \n";
    std::cout << "You can try and fight the dragon, but you need to be ridiculously strong (Toughness 10+).\n";
    std::cout << "Otherwise, you may try to cast a spell or something to kill him, if you're a mage, well, you\n";
    std::cout << "cast successfully and kill him! GG. Otherwise you need Intelligence 9+ and MF 5+"<< std::endl;
    std::cout << "Remember:\nYour Intelligence: " << p.getI() << "\nYour Mental Fortitude: " <<
    p.getMF() << "\nYour Toughness: " << p.getT() << std::endl;
    std::cout << "Ready to cast? [1]\nOr do you wanna try your luck at hand to hand combat? [2]\n";
    int r;
    std::cin >> r;

    if(r == 1){
        if(p.getI() >= 9 && p.getMF() >= 5){
            std::cout << "You successfully cast a spell, and beat the dragon, the princess rewards you..." << std::endl;
        } else {
            std::cout << "You tried to cast the spell, but failed miserably. You and the princess both die." << std::endl;
            goto END;
        }
    }
    if(r == 2){
        if(p.getT() >= 10){
            std::cout << "Jesus.... you beat the dragon. You go to hug the princess but you break her spine... you lunatic.";
            goto GO;
        } else {
            std::cout << "You try to beat a Dragon?? Really? No way in hell." << std::endl;
            goto END;
        }
    }
    if(r == 69420){
        std::cout << "Woah, very impressive, you found the secret ending!" << std::endl;
        std::cout << "The dragon realizes he stands no chance against you, and he runs away.\n";
        std::cout << "The princess is your until the end of time.\n";
        goto GO;
    }

    GO:
    std::cout << "Hope you enjoyed the game!" << std::endl;
    END:
    std::cout << "Tough luck.... Play again? (Press [1] to play again, any other number to quit.)";
    int y;
    std::cin >> y;

    if(y == 1){goto Retry;}
    else {std::cout << "See you next time!";}

    return p;
}
