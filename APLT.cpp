// author: Georgi Lekov
#include "APLT.h"

APLT::APLT()
{
    // populating the values for all the 7 coordinates
    //
    // the 0th coordinate is always 6
    for( int i = 0 ; i < QR::UNDEFINED_VERSION; i++){
        algn_coords[i].c0 = 6;
    }

    using namespace QR;
    algn_coords[V_TWO         ].c1 = 18; algn_coords[V_TWO         ].c2 = 0 ; algn_coords[V_TWO         ].c3 = 0 ;  
    algn_coords[V_THREE       ].c1 = 22; algn_coords[V_THREE       ].c2 = 0 ; algn_coords[V_THREE       ].c3 = 0 ;
    algn_coords[V_FOUR        ].c1 = 26; algn_coords[V_FOUR        ].c2 = 0 ; algn_coords[V_FOUR        ].c3 = 0 ;
    algn_coords[V_FIVE        ].c1 = 30; algn_coords[V_FIVE        ].c2 = 0 ; algn_coords[V_FIVE        ].c3 = 0 ;
    algn_coords[V_SIX         ].c1 = 34; algn_coords[V_SIX         ].c2 = 0 ; algn_coords[V_SIX         ].c3 = 0 ;
    algn_coords[V_SEVEN       ].c1 = 22; algn_coords[V_SEVEN       ].c2 = 38; algn_coords[V_SEVEN       ].c3 = 0 ;
    algn_coords[V_EIGHT       ].c1 = 24; algn_coords[V_EIGHT       ].c2 = 42; algn_coords[V_EIGHT       ].c3 = 0 ;
    algn_coords[V_NINE        ].c1 = 26; algn_coords[V_NINE        ].c2 = 46; algn_coords[V_NINE        ].c3 = 0 ;
    algn_coords[V_TEN         ].c1 = 28; algn_coords[V_TEN         ].c2 = 50; algn_coords[V_TEN         ].c3 = 0 ;
    algn_coords[V_ELEVEN      ].c1 = 30; algn_coords[V_ELEVEN      ].c2 = 54; algn_coords[V_ELEVEN      ].c3 = 0 ;
    algn_coords[V_TWELVE      ].c1 = 32; algn_coords[V_TWELVE      ].c2 = 58; algn_coords[V_TWELVE      ].c3 = 0 ;
    algn_coords[V_THIRTEEN    ].c1 = 34; algn_coords[V_THIRTEEN    ].c2 = 62; algn_coords[V_THIRTEEN    ].c3 = 0 ;
    algn_coords[V_FOURTEEN    ].c1 = 26; algn_coords[V_FOURTEEN    ].c2 = 46; algn_coords[V_FOURTEEN    ].c3 = 66;
    algn_coords[V_FIFTEEN     ].c1 = 26; algn_coords[V_FIFTEEN     ].c2 = 48; algn_coords[V_FIFTEEN     ].c3 = 70;
    algn_coords[V_SIXTEEN     ].c1 = 26; algn_coords[V_SIXTEEN     ].c2 = 50; algn_coords[V_SIXTEEN     ].c3 = 74;
    algn_coords[V_SEVENTEEN   ].c1 = 30; algn_coords[V_SEVENTEEN   ].c2 = 54; algn_coords[V_SEVENTEEN   ].c3 = 78;
    algn_coords[V_EIGHTEEN    ].c1 = 30; algn_coords[V_EIGHTEEN    ].c2 = 56; algn_coords[V_EIGHTEEN    ].c3 = 82;
    algn_coords[V_NINETEEN    ].c1 = 30; algn_coords[V_NINETEEN    ].c2 = 58; algn_coords[V_NINETEEN    ].c3 = 86;
    algn_coords[V_TWENTY      ].c1 = 34; algn_coords[V_TWENTY      ].c2 = 62; algn_coords[V_TWENTY      ].c3 = 90;
    algn_coords[V_TWENTY_ONE  ].c1 = 28; algn_coords[V_TWENTY_ONE  ].c2 = 50; algn_coords[V_TWENTY_ONE  ].c3 = 72;
    algn_coords[V_TWENTY_TWO  ].c1 = 26; algn_coords[V_TWENTY_TWO  ].c2 = 50; algn_coords[V_TWENTY_TWO  ].c3 = 74;
    algn_coords[V_TWENTY_THREE].c1 = 30; algn_coords[V_TWENTY_THREE].c2 = 54; algn_coords[V_TWENTY_THREE].c3 = 78;
    algn_coords[V_TWENTY_FOUR ].c1 = 28; algn_coords[V_TWENTY_FOUR ].c2 = 54; algn_coords[V_TWENTY_FOUR ].c3 = 80;
    algn_coords[V_TWENTY_FIVE ].c1 = 32; algn_coords[V_TWENTY_FIVE ].c2 = 58; algn_coords[V_TWENTY_FIVE ].c3 = 84;
    algn_coords[V_TWENTY_SIX  ].c1 = 30; algn_coords[V_TWENTY_SIX  ].c2 = 58; algn_coords[V_TWENTY_SIX  ].c3 = 86;
    algn_coords[V_TWENTY_SEVEN].c1 = 34; algn_coords[V_TWENTY_SEVEN].c2 = 62; algn_coords[V_TWENTY_SEVEN].c3 = 90;
    algn_coords[V_TWENTY_EIGHT].c1 = 26; algn_coords[V_TWENTY_EIGHT].c2 = 50; algn_coords[V_TWENTY_EIGHT].c3 = 74;
    algn_coords[V_TWENTY_NINE ].c1 = 30; algn_coords[V_TWENTY_NINE ].c2 = 54; algn_coords[V_TWENTY_NINE ].c3 = 78;
    algn_coords[V_THIRTY      ].c1 = 26; algn_coords[V_THIRTY      ].c2 = 52; algn_coords[V_THIRTY      ].c3 = 78;
    algn_coords[V_THIRTY_ONE  ].c1 = 30; algn_coords[V_THIRTY_ONE  ].c2 = 56; algn_coords[V_THIRTY_ONE  ].c3 = 82;
    algn_coords[V_THIRTY_TWO  ].c1 = 34; algn_coords[V_THIRTY_TWO  ].c2 = 60; algn_coords[V_THIRTY_TWO  ].c3 = 86;
    algn_coords[V_THIRTY_THREE].c1 = 30; algn_coords[V_THIRTY_THREE].c2 = 58; algn_coords[V_THIRTY_THREE].c3 = 86;
    algn_coords[V_THIRTY_FOUR ].c1 = 34; algn_coords[V_THIRTY_FOUR ].c2 = 62; algn_coords[V_THIRTY_FOUR ].c3 = 90;
    algn_coords[V_THIRTY_FIVE ].c1 = 30; algn_coords[V_THIRTY_FIVE ].c2 = 54; algn_coords[V_THIRTY_FIVE ].c3 = 78;
    algn_coords[V_THIRTY_SIX  ].c1 = 24; algn_coords[V_THIRTY_SIX  ].c2 = 50; algn_coords[V_THIRTY_SIX  ].c3 = 76;
    algn_coords[V_THIRTY_SEVEN].c1 = 28; algn_coords[V_THIRTY_SEVEN].c2 = 54; algn_coords[V_THIRTY_SEVEN].c3 = 80;
    algn_coords[V_THIRTY_EIGHT].c1 = 32; algn_coords[V_THIRTY_EIGHT].c2 = 58; algn_coords[V_THIRTY_EIGHT].c3 = 84;
    algn_coords[V_THIRTY_NINE ].c1 = 26; algn_coords[V_THIRTY_NINE ].c2 = 54; algn_coords[V_THIRTY_NINE ].c3 = 82;
    algn_coords[V_FORTY       ].c1 = 30; algn_coords[V_FORTY       ].c2 = 58; algn_coords[V_FORTY       ].c3 = 86;

    algn_coords[V_TWO         ].c4 = 0  ; algn_coords[V_TWO         ].c5 = 0  ; algn_coords[V_TWO         ].c6  = 0  ;
    algn_coords[V_THREE       ].c4 = 0  ; algn_coords[V_THREE       ].c5 = 0  ; algn_coords[V_THREE       ].c6  = 0  ;
    algn_coords[V_FOUR        ].c4 = 0  ; algn_coords[V_FOUR        ].c5 = 0  ; algn_coords[V_FOUR        ].c6  = 0  ;
    algn_coords[V_FIVE        ].c4 = 0  ; algn_coords[V_FIVE        ].c5 = 0  ; algn_coords[V_FIVE        ].c6  = 0  ;
    algn_coords[V_SIX         ].c4 = 0  ; algn_coords[V_SIX         ].c5 = 0  ; algn_coords[V_SIX         ].c6  = 0  ;
    algn_coords[V_SEVEN       ].c4 = 0  ; algn_coords[V_SEVEN       ].c5 = 0  ; algn_coords[V_SEVEN       ].c6  = 0  ;
    algn_coords[V_EIGHT       ].c4 = 0  ; algn_coords[V_EIGHT       ].c5 = 0  ; algn_coords[V_EIGHT       ].c6  = 0  ;
    algn_coords[V_NINE        ].c4 = 0  ; algn_coords[V_NINE        ].c5 = 0  ; algn_coords[V_NINE        ].c6  = 0  ;
    algn_coords[V_TEN         ].c4 = 0  ; algn_coords[V_TEN         ].c5 = 0  ; algn_coords[V_TEN         ].c6 = 0  ;
    algn_coords[V_ELEVEN      ].c4 = 0  ; algn_coords[V_ELEVEN      ].c5 = 0  ; algn_coords[V_ELEVEN      ].c6 = 0  ;
    algn_coords[V_TWELVE      ].c4 = 0  ; algn_coords[V_TWELVE      ].c5 = 0  ; algn_coords[V_TWELVE      ].c6 = 0  ;
    algn_coords[V_THIRTEEN    ].c4 = 0  ; algn_coords[V_THIRTEEN    ].c5 = 0  ; algn_coords[V_THIRTEEN    ].c6 = 0  ;
    algn_coords[V_FOURTEEN    ].c4 = 0  ; algn_coords[V_FOURTEEN    ].c5 = 0  ; algn_coords[V_FOURTEEN    ].c6 = 0  ;
    algn_coords[V_FIFTEEN     ].c4 = 0  ; algn_coords[V_FIFTEEN     ].c5 = 0  ; algn_coords[V_FIFTEEN     ].c6 = 0  ;
    algn_coords[V_SIXTEEN     ].c4 = 0  ; algn_coords[V_SIXTEEN     ].c5 = 0  ; algn_coords[V_SIXTEEN     ].c6 = 0  ;
    algn_coords[V_SEVENTEEN   ].c4 = 0  ; algn_coords[V_SEVENTEEN   ].c5 = 0  ; algn_coords[V_SEVENTEEN   ].c6 = 0  ;
    algn_coords[V_EIGHTEEN    ].c4 = 0  ; algn_coords[V_EIGHTEEN    ].c5 = 0  ; algn_coords[V_EIGHTEEN    ].c6 = 0  ;
    algn_coords[V_NINETEEN    ].c4 = 0  ; algn_coords[V_NINETEEN    ].c5 = 0  ; algn_coords[V_NINETEEN    ].c6 = 0  ;
    algn_coords[V_TWENTY      ].c4 = 0  ; algn_coords[V_TWENTY      ].c5 = 0  ; algn_coords[V_TWENTY      ].c6 = 0  ;
    algn_coords[V_TWENTY_ONE  ].c4 = 94 ; algn_coords[V_TWENTY_ONE  ].c5 = 0  ; algn_coords[V_TWENTY_ONE  ].c6 = 0  ;
    algn_coords[V_TWENTY_TWO  ].c4 = 98 ; algn_coords[V_TWENTY_TWO  ].c5 = 0  ; algn_coords[V_TWENTY_TWO  ].c6 = 0  ;
    algn_coords[V_TWENTY_THREE].c4 = 102; algn_coords[V_TWENTY_THREE].c5 = 0  ; algn_coords[V_TWENTY_THREE].c6 = 0  ;
    algn_coords[V_TWENTY_FOUR ].c4 = 106; algn_coords[V_TWENTY_FOUR ].c5 = 0  ; algn_coords[V_TWENTY_FOUR ].c6 = 0  ;
    algn_coords[V_TWENTY_FIVE ].c4 = 110; algn_coords[V_TWENTY_FIVE ].c5 = 0  ; algn_coords[V_TWENTY_FIVE ].c6 = 0  ;
    algn_coords[V_TWENTY_SIX  ].c4 = 114; algn_coords[V_TWENTY_SIX  ].c5 = 0  ; algn_coords[V_TWENTY_SIX  ].c6 = 0  ;
    algn_coords[V_TWENTY_SEVEN].c4 = 118; algn_coords[V_TWENTY_SEVEN].c5 = 0  ; algn_coords[V_TWENTY_SEVEN].c6 = 0  ;
    algn_coords[V_TWENTY_EIGHT].c4 = 98 ; algn_coords[V_TWENTY_EIGHT].c5 = 122; algn_coords[V_TWENTY_EIGHT].c6 = 0  ;
    algn_coords[V_TWENTY_NINE ].c4 = 102; algn_coords[V_TWENTY_NINE ].c5 = 126; algn_coords[V_TWENTY_NINE ].c6 = 0  ;
    algn_coords[V_THIRTY      ].c4 = 104; algn_coords[V_THIRTY      ].c5 = 130; algn_coords[V_THIRTY      ].c6 = 0  ;
    algn_coords[V_THIRTY_ONE  ].c4 = 108; algn_coords[V_THIRTY_ONE  ].c5 = 134; algn_coords[V_THIRTY_ONE  ].c6 = 0  ;
    algn_coords[V_THIRTY_TWO  ].c4 = 112; algn_coords[V_THIRTY_TWO  ].c5 = 138; algn_coords[V_THIRTY_TWO  ].c6 = 0  ;
    algn_coords[V_THIRTY_THREE].c4 = 114; algn_coords[V_THIRTY_THREE].c5 = 142; algn_coords[V_THIRTY_THREE].c6 = 0  ;
    algn_coords[V_THIRTY_FOUR ].c4 = 118; algn_coords[V_THIRTY_FOUR ].c5 = 146; algn_coords[V_THIRTY_FOUR ].c6 = 0  ;
    algn_coords[V_THIRTY_FIVE ].c4 = 102; algn_coords[V_THIRTY_FIVE ].c5 = 126; algn_coords[V_THIRTY_FIVE ].c6 = 150;
    algn_coords[V_THIRTY_SIX  ].c4 = 102; algn_coords[V_THIRTY_SIX  ].c5 = 128; algn_coords[V_THIRTY_SIX  ].c6 = 154;
    algn_coords[V_THIRTY_SEVEN].c4 = 106; algn_coords[V_THIRTY_SEVEN].c5 = 132; algn_coords[V_THIRTY_SEVEN].c6 = 158;
    algn_coords[V_THIRTY_EIGHT].c4 = 110; algn_coords[V_THIRTY_EIGHT].c5 = 136; algn_coords[V_THIRTY_EIGHT].c6 = 162;
    algn_coords[V_THIRTY_NINE ].c4 = 110; algn_coords[V_THIRTY_NINE ].c5 = 138; algn_coords[V_THIRTY_NINE ].c6 = 166;
    algn_coords[V_FORTY       ].c4 = 114; algn_coords[V_FORTY       ].c5 = 142; algn_coords[V_FORTY       ].c6 = 170;
}

APLT::~APLT()
{}
