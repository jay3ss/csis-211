/** @file ToyBox.h **/

#ifndef _TOY_BOX_H
#define _TOY_BOX_H

enum Color {BLACK, RED, BLUE, GREEN, YELLOW, WHITE};

#include "PlainBox.h"

template<class ItemType>
class ToyBox : public PlainBox<ItemType>
{
private:
    Color boxColor;

public:
    ToyBox();
    ToyBox(const Color &theColor);
    ToyBox(const ItemType& theItem, const Color& theColor);
    Color getColor() const;
};

#endif // _TOY_BOX_H