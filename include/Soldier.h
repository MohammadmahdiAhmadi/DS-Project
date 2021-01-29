#ifndef SOLDIER_H
#define SOLDIER_H


class Soldier
{
    public:
        Soldier(int power=20, int castleId=-1);
        virtual ~Soldier();

    int Power;
    int CastleId;


};

#endif // SOLDIER_H
