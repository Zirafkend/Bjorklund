//
// Created by Nikola on 14/04/2018.
//

#ifndef BJORKLUND_BJORKLUND_H
#define BJORKLUND_BJORKLUND_H

//
// Created by Nikola on 23/03/2018.
//
#ifndef HARMONY_BJORKLUND_H
#define HARMONY_BJORKLUND_H
#include <iostream>
#include <vector>
#include <cmath>
#include <map>




std::vector<int> bjorklund(int step, int pulse) {
    int pauses = step - pulse;
    int remainder = pauses % pulse;
    int per_pulse = (int) floor(pauses / pulse);
    int noskip = (remainder == 0) ? 0 : (int) floor(pulse / remainder);
    int skipXTime = (noskip == 0) ? 0 : (int) floor((pulse - remainder)/noskip);
    std::vector<int> rhythm;
    int count = 0;
    int skipper = 0;
    for (int i = 1; i <= step; i++) {
        if (count == 0) {
            rhythm.push_back(1);
            count = per_pulse;
            if (remainder > 0 && skipper == 0) {
                count++;
                remainder--;
                skipper = (skipXTime > 0) ? noskip : 0;
                skipXTime--;
            } else {
                skipper--;
            }
        } else {
            rhythm.push_back(0);
            count--;
        }
    }
    return rhythm;
}


std::map<std::string, std::vector<int>> init_euclidean_pressets(){
    std::map<std::string, std::vector<int>> pressets;
    pressets["afro"] = bjorklund(3 ,2);
    pressets["calypso"] = bjorklund(4 ,3);
    pressets["khalif"] = bjorklund(5 ,2);
    pressets["rumanian"] = bjorklund(5 ,3);
    pressets["bulgarian"] = bjorklund(7 ,3);
    pressets["tresillo"] = bjorklund(8 ,3);
    pressets["tango"] = bjorklund(8 ,5);
    pressets["bendir"] = bjorklund(8 ,7);
    pressets["aksak"] = bjorklund(9 ,4);
    pressets["venda"] = bjorklund(9 ,5);
    pressets["zappa"] = bjorklund(11 ,4);
    pressets["flamenco"] = bjorklund(12 ,4);
    pressets["mpre"] = bjorklund(12 ,7);
    pressets["semai"] = bjorklund(6 ,5);
    pressets["nawakhat"] = bjorklund(7 ,6);
    pressets["moussorgsky"] = bjorklund(11 ,5);
    pressets["bossa"] = bjorklund(16 ,5);
    pressets["samba"] = bjorklund(16 ,7);
    pressets["maibo"] = bjorklund(16 ,9);
    pressets["pygmies"] = bjorklund(24 ,1);     // TODO is one triplet in a  triolet
    pressets["sangha"] = bjorklund(24 ,3);
    return pressets;
}


#endif //HARMONY_BJORKLUND_H


#endif //BJORKLUND_BJORKLUND_H
