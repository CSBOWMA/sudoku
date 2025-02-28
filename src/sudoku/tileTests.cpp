#include "tile.h"
#include <cassert>
#include <iostream>


int main() {
    
    Tile* tiles[23];
    
    tiles[22] = new Tile();

    assert(tiles[22]->getPreset() == true);
    assert(tiles[22]->getNumber() == 0);
    assert(tiles[22]->valid() == false);
    std::cout << "default constructor test passed" << std::endl;

    for(int i = 0; i < 10; i++) {
        tiles[22]->setNumber(i);
        assert(tiles[22]->getNumber() == i);
        assert(tiles[22]->getNumber(true) == i+'0');
        assert(tiles[22]->getPreset() == true);
    }
    tiles[22]->setNumber(0);
    for(int i = -255; i > 0; i++) {
        tiles[22]->setNumber(i);
        assert(tiles[22]->getNumber(false) == 0);
        assert(tiles[22]->getNumber(true) == '0');
        assert(tiles[22]->getPreset() == true);
    }

    
    for(int i = 10; i < 128; i++) {
        tiles[22]->setNumber(i);
        assert(tiles[22]->getNumber(false) == 0);
        assert(tiles[22]->getNumber(true) == '0');
        assert(tiles[22]->getPreset() == true);
    }

    tiles[22]->setPreset(false);
    for(int i = 0; i < 10; i++) {
        tiles[22]->setNumber(i);
        assert(tiles[22]->getNumber() == i);
        assert(tiles[22]->getNumber(true) == i+'0');
        assert(tiles[22]->getPreset() == false);
        assert(tiles[22]->valid());
    }
    tiles[22]->setNumber(0);
    for(int i = -255; i > 0; i++) {
        tiles[22]->setNumber(i);
        assert(tiles[22]->getNumber(false) == 0);
        assert(tiles[22]->getNumber(true) == '0');
        assert(tiles[22]->getPreset() == false);
        assert(tiles[22]->valid());
    }

    
    for(int i = 10; i < 128; i++) {
        tiles[22]->setNumber(i);
        assert(tiles[22]->getNumber(false) == 0);
        assert(tiles[22]->getNumber(true) == '0');
        assert(tiles[22]->getPreset() == false);
    }
    std::cout << "valid() test passed" << std::endl;
    std::cout << "setNumber(int) test passed" << std::endl;
    
    for(int i = 0; i < 10; i++) {
        tiles[22]->setNumber(char(i+'0'));
        assert(tiles[22]->getNumber() == i);
        assert(tiles[22]->getNumber(true) == i+'0');
        assert(tiles[22]->getPreset() == false);
    }

    tiles[22]->setNumber(0);
    for(int i = 10; i < 100; i++) {
        tiles[22]->setNumber(i + '0');
        assert(tiles[22]->getNumber() == 0);
        assert(tiles[22]->getNumber(true) == '0');
        assert(tiles[22]->getPreset() == false);
    }
    
    tiles[22]->setPreset(true);

    for(int i = 0; i < 10; i++) {
        tiles[22]->setNumber(char(i+'0'));
        assert(tiles[22]->getNumber() == i);
        assert(tiles[22]->getNumber(true) == i+'0');
        assert(tiles[22]->getPreset() == true);
    }

    tiles[22]->setNumber(0);
    for(int i = 10; i < 100; i++) {
        tiles[22]->setNumber(i + '0');
        assert(tiles[22]->getNumber() == 0);
        assert(tiles[22]->getNumber(true) == '0');
        assert(tiles[22]->getPreset() == true);
    }


    std::cout << "setNumber(char) test passed" << std::endl;
    std::cout << "getNumber() test passed" << std::endl;
 
    tiles[22]->setPreset(true);
    assert(tiles[22]->getPreset() == true);
    
    tiles[22]->setPreset(false);
    assert(tiles[22]->getPreset() == false);
    
    
    

    std::cout << "setPreset test passed" << std::endl;
    std::cout << "getPreset test passed" << std::endl;

    for(int i = 0; i <  10; i++) {
        assert(tiles[22]->updateNumber(char(i)));
        assert(tiles[22]->getNumber() == i);
        assert(tiles[22]->getNumber(true) == '0' + i);
        assert(tiles[22]->getPreset() == false);
    }

    for(int i = 10; i <  128; i++) {
        assert(tiles[22]->updateNumber(char(i + '0')) == false);
        assert(tiles[22]->getNumber() == 9);
        assert(tiles[22]->getPreset() == false);
    }
    
    tiles[22]->setPreset(true);
    for(int i = -255; i <  128; i++) {
        assert(tiles[22]->updateNumber(char(i)) == false);
        assert(tiles[22]->getNumber() == 9);
        assert(tiles[22]->getPreset() == true);
    }



    std::cout << "updateNumber(char) test passed" << std::endl; 

    tiles[22]->setPreset(false);
    for(int i = 0; i <  10; i++) {
        assert(tiles[22]->updateNumber(i) == true);
        assert(tiles[22]->getNumber() == i);
        assert(tiles[22]->getPreset() == false);
    }

    for(int i = 10; i <  48; i++) {
        assert(tiles[22]->updateNumber(char(i)) == false);
        assert(tiles[22]->getNumber() == 9);
        assert(tiles[22]->getPreset() == false);
    }
    
    tiles[22]->setPreset(true);
    for(int i = -255; i <  127; i++) {
        assert(tiles[22]->updateNumber(char(i)) == false);
        assert(tiles[22]->getNumber() == 9);
        assert(tiles[22]->getPreset() == true);
    }
    std::cout << "updateNumber(int) test passed" << std::endl;

    //initialize and test sudokuTile(int)
    for (int i = 0; i < 10; i++) {
        tiles[i] = new Tile(i);
        assert(tiles[i]->getNumber() ==  i);

    }

    tiles[18] = new Tile(-1);
    tiles[19] = new Tile(10);

    assert(tiles[18]->getNumber() == 0);
    assert(tiles[19]->getNumber() == 0);
    assert(tiles[0]->getPreset() == false);
    assert(tiles[18]->getPreset() == false);
    assert(tiles[19]->getPreset() == false);
    assert(tiles[1]->getPreset() == true);

    std::cout << "int constructor test passed" << std::endl;  
    
    char num; 
    for (int i = 10; i < 20; i++) {
        num = i%10+'0';
        tiles[i] = new Tile(num);
        assert(tiles[i]->getNumber() ==  i%10);
    }

    tiles[20] = new Tile('a');

    tiles[21] = new Tile('/');

    assert(tiles[18]->getNumber() == 8);
    assert(tiles[19]->getNumber() == 9);
    assert(tiles[11]->getPreset() == true);
    assert(tiles[10]->getPreset() == false);
    assert(tiles[20]->getPreset() == false);

    assert(tiles[20]->getNumber() == 0);
    assert(tiles[21]->getNumber() == 0);


    std::cout << "char constructor test passed" << std::endl;  
    



    for(int i = 0; i < 23; i++) {
        tiles[i]->invalidate();
        assert(tiles[i]->getNumber() == 0);
        assert(tiles[i]->getPreset() == true);
        delete tiles[i];
    }

    return 0;
}




