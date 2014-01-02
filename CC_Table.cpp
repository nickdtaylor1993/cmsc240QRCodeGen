#include "CC_Table.h"

CC_Table::CC_Table()
{
    char_capacity[ECC_L][ALPHA_NUM][25  ] = V_ONE         ;
    char_capacity[ECC_L][ALPHA_NUM][47  ] = V_TWO         ;
    char_capacity[ECC_L][ALPHA_NUM][77  ] = V_THREE       ;
    char_capacity[ECC_L][ALPHA_NUM][114 ] = V_FOUR        ;
    char_capacity[ECC_L][ALPHA_NUM][154 ] = V_FIVE        ;
    char_capacity[ECC_L][ALPHA_NUM][195 ] = V_SIX         ;
    char_capacity[ECC_L][ALPHA_NUM][224 ] = V_SEVEN       ;
    char_capacity[ECC_L][ALPHA_NUM][279 ] = V_EIGHT       ;
    char_capacity[ECC_L][ALPHA_NUM][335 ] = V_NINE        ;
    char_capacity[ECC_L][ALPHA_NUM][395 ] = V_TEN         ;
    char_capacity[ECC_L][ALPHA_NUM][468 ] = V_ELEVEN      ;
    char_capacity[ECC_L][ALPHA_NUM][535 ] = V_TWELVE      ;
    char_capacity[ECC_L][ALPHA_NUM][619 ] = V_THIRTEEN    ;
    char_capacity[ECC_L][ALPHA_NUM][667 ] = V_FOURTEEN    ;
    char_capacity[ECC_L][ALPHA_NUM][758 ] = V_FIFTEEN     ;
    char_capacity[ECC_L][ALPHA_NUM][854 ] = V_SIXTEEN     ;
    char_capacity[ECC_L][ALPHA_NUM][938 ] = V_SEVENTEEN   ;
    char_capacity[ECC_L][ALPHA_NUM][1046] = V_EIGHTEEN    ;
    char_capacity[ECC_L][ALPHA_NUM][1153] = V_NINETEEN    ;
    char_capacity[ECC_L][ALPHA_NUM][1249] = V_TWENTY      ;
    char_capacity[ECC_L][ALPHA_NUM][1352] = V_TWENTY_ONE  ;
    char_capacity[ECC_L][ALPHA_NUM][1460] = V_TWENTY_TWO  ;
    char_capacity[ECC_L][ALPHA_NUM][1588] = V_TWENTY_THREE;
    char_capacity[ECC_L][ALPHA_NUM][1704] = V_TWENTY_FOUR ;
    char_capacity[ECC_L][ALPHA_NUM][1853] = V_TWENTY_FIVE ;
    char_capacity[ECC_L][ALPHA_NUM][1990] = V_TWENTY_SIX  ;
    char_capacity[ECC_L][ALPHA_NUM][2132] = V_TWENTY_SEVEN;
    char_capacity[ECC_L][ALPHA_NUM][2223] = V_TWENTY_EIGHT;
    char_capacity[ECC_L][ALPHA_NUM][2369] = V_TWENTY_NINE ;
    char_capacity[ECC_L][ALPHA_NUM][2520] = V_THIRTY      ;
    char_capacity[ECC_L][ALPHA_NUM][2677] = V_THIRTY_ONE  ;
    char_capacity[ECC_L][ALPHA_NUM][2840] = V_THIRTY_TWO  ;
    char_capacity[ECC_L][ALPHA_NUM][3009] = V_THIRTY_THREE;
    char_capacity[ECC_L][ALPHA_NUM][3183] = V_THIRTY_FOUR ;
    char_capacity[ECC_L][ALPHA_NUM][3351] = V_THIRTY_FIVE ;
    char_capacity[ECC_L][ALPHA_NUM][3537] = V_THIRTY_SIX  ;
    char_capacity[ECC_L][ALPHA_NUM][3729] = V_THIRTY_SEVEN;
    char_capacity[ECC_L][ALPHA_NUM][3927] = V_THIRTY_EIGHT;
    char_capacity[ECC_L][ALPHA_NUM][4087] = V_THIRTY_NINE ;
    char_capacity[ECC_L][ALPHA_NUM][4296] = V_FORTY       ;

    char_capacity[ECC_L][NUM][41  ] = V_ONE          ;
    char_capacity[ECC_L][NUM][77  ] = V_TWO         ;
    char_capacity[ECC_L][NUM][127 ] = V_THREE       ;
    char_capacity[ECC_L][NUM][187 ] = V_FOUR        ;
    char_capacity[ECC_L][NUM][255 ] = V_FIVE        ;
    char_capacity[ECC_L][NUM][322 ] = V_SIX         ;
    char_capacity[ECC_L][NUM][370 ] = V_SEVEN       ;
    char_capacity[ECC_L][NUM][461 ] = V_EIGHT       ;
    char_capacity[ECC_L][NUM][552 ] = V_NINE        ;
    char_capacity[ECC_L][NUM][652 ] = V_TEN         ;
    char_capacity[ECC_L][NUM][772 ] = V_ELEVEN      ;
    char_capacity[ECC_L][NUM][883 ] = V_TWELVE      ;
    char_capacity[ECC_L][NUM][1022] = V_THIRTEEN    ;
    char_capacity[ECC_L][NUM][1101] = V_FOURTEEN    ;
    char_capacity[ECC_L][NUM][1250] = V_FIFTEEN     ;
    char_capacity[ECC_L][NUM][1408] = V_SIXTEEN     ;
    char_capacity[ECC_L][NUM][1548] = V_SEVENTEEN   ;
    char_capacity[ECC_L][NUM][1725] = V_EIGHTEEN    ;
    char_capacity[ECC_L][NUM][1903] = V_NINETEEN    ;
    char_capacity[ECC_L][NUM][2061] = V_TWENTY      ;
    char_capacity[ECC_L][NUM][2232] = V_TWENTY_ONE  ;
    char_capacity[ECC_L][NUM][2409] = V_TWENTY_TWO  ;
    char_capacity[ECC_L][NUM][2620] = V_TWENTY_THREE;
    char_capacity[ECC_L][NUM][2812] = V_TWENTY_FOUR ;
    char_capacity[ECC_L][NUM][3057] = V_TWENTY_FIVE ;
    char_capacity[ECC_L][NUM][3283] = V_TWENTY_SIX  ;
    char_capacity[ECC_L][NUM][3517] = V_TWENTY_SEVEN;
    char_capacity[ECC_L][NUM][3669] = V_TWENTY_EIGHT;
    char_capacity[ECC_L][NUM][3909] = V_TWENTY_NINE ;
    char_capacity[ECC_L][NUM][4158] = V_THIRTY      ;
    char_capacity[ECC_L][NUM][4417] = V_THIRTY_ONE  ;
    char_capacity[ECC_L][NUM][4686] = V_THIRTY_TWO  ;
    char_capacity[ECC_L][NUM][4965] = V_THIRTY_THREE;
    char_capacity[ECC_L][NUM][5253] = V_THIRTY_FOUR ;
    char_capacity[ECC_L][NUM][5529] = V_THIRTY_FIVE ;
    char_capacity[ECC_L][NUM][5836] = V_THIRTY_SIX  ;
    char_capacity[ECC_L][NUM][6153] = V_THIRTY_SEVEN;
    char_capacity[ECC_L][NUM][6479] = V_THIRTY_EIGHT;
    char_capacity[ECC_L][NUM][6743] = V_THIRTY_NINE ;
    char_capacity[ECC_L][NUM][7089] = V_FORTY       ;

    char_capacity[ECC_M][ALPHA_NUM][20  ] = V_ONE          ;
    char_capacity[ECC_M][ALPHA_NUM][38  ] = V_TWO         ;
    char_capacity[ECC_M][ALPHA_NUM][61  ] = V_THREE       ;
    char_capacity[ECC_M][ALPHA_NUM][90  ] = V_FOUR        ;
    char_capacity[ECC_M][ALPHA_NUM][122 ] = V_FIVE        ;
    char_capacity[ECC_M][ALPHA_NUM][154 ] = V_SIX         ;
    char_capacity[ECC_M][ALPHA_NUM][178 ] = V_SEVEN       ;
    char_capacity[ECC_M][ALPHA_NUM][221 ] = V_EIGHT       ;
    char_capacity[ECC_M][ALPHA_NUM][262 ] = V_NINE        ;
    char_capacity[ECC_M][ALPHA_NUM][311 ] = V_TEN         ;
    char_capacity[ECC_M][ALPHA_NUM][366 ] = V_ELEVEN      ;
    char_capacity[ECC_M][ALPHA_NUM][419 ] = V_TWELVE      ;
    char_capacity[ECC_M][ALPHA_NUM][483 ] = V_THIRTEEN    ;
    char_capacity[ECC_M][ALPHA_NUM][528 ] = V_FOURTEEN    ;
    char_capacity[ECC_M][ALPHA_NUM][600 ] = V_FIFTEEN     ;
    char_capacity[ECC_M][ALPHA_NUM][656 ] = V_SIXTEEN     ;
    char_capacity[ECC_M][ALPHA_NUM][734 ] = V_SEVENTEEN   ;
    char_capacity[ECC_M][ALPHA_NUM][816 ] = V_EIGHTEEN    ;
    char_capacity[ECC_M][ALPHA_NUM][909 ] = V_NINETEEN    ;
    char_capacity[ECC_M][ALPHA_NUM][970 ] = V_TWENTY      ;
    char_capacity[ECC_M][ALPHA_NUM][1035] = V_TWENTY_ONE  ;
    char_capacity[ECC_M][ALPHA_NUM][1134] = V_TWENTY_TWO  ;
    char_capacity[ECC_M][ALPHA_NUM][1248] = V_TWENTY_THREE;
    char_capacity[ECC_M][ALPHA_NUM][1326] = V_TWENTY_FOUR ;
    char_capacity[ECC_M][ALPHA_NUM][1451] = V_TWENTY_FIVE ;
    char_capacity[ECC_M][ALPHA_NUM][1542] = V_TWENTY_SIX  ;
    char_capacity[ECC_M][ALPHA_NUM][1637] = V_TWENTY_SEVEN;
    char_capacity[ECC_M][ALPHA_NUM][1732] = V_TWENTY_EIGHT;
    char_capacity[ECC_M][ALPHA_NUM][1839] = V_TWENTY_NINE ;
    char_capacity[ECC_M][ALPHA_NUM][1994] = V_THIRTY      ;
    char_capacity[ECC_M][ALPHA_NUM][2113] = V_THIRTY_ONE  ;
    char_capacity[ECC_M][ALPHA_NUM][2238] = V_THIRTY_TWO  ;
    char_capacity[ECC_M][ALPHA_NUM][2369] = V_THIRTY_THREE;
    char_capacity[ECC_M][ALPHA_NUM][2506] = V_THIRTY_FOUR ;
    char_capacity[ECC_M][ALPHA_NUM][2632] = V_THIRTY_FIVE ;
    char_capacity[ECC_M][ALPHA_NUM][2780] = V_THIRTY_SIX  ;
    char_capacity[ECC_M][ALPHA_NUM][2894] = V_THIRTY_SEVEN;
    char_capacity[ECC_M][ALPHA_NUM][3054] = V_THIRTY_EIGHT;
    char_capacity[ECC_M][ALPHA_NUM][3220] = V_THIRTY_NINE ;
    char_capacity[ECC_M][ALPHA_NUM][3391] = V_FORTY       ;

    char_capacity[ECC_M][NUM][34  ] = V_ONE          ;
    char_capacity[ECC_M][NUM][63  ] = V_TWO         ;
    char_capacity[ECC_M][NUM][101 ] = V_THREE       ;
    char_capacity[ECC_M][NUM][149 ] = V_FOUR        ;
    char_capacity[ECC_M][NUM][202 ] = V_FIVE        ;
    char_capacity[ECC_M][NUM][255 ] = V_SIX         ;
    char_capacity[ECC_M][NUM][293 ] = V_SEVEN       ;
    char_capacity[ECC_M][NUM][365 ] = V_EIGHT       ;
    char_capacity[ECC_M][NUM][432 ] = V_NINE        ;
    char_capacity[ECC_M][NUM][513 ] = V_TEN         ;
    char_capacity[ECC_M][NUM][604 ] = V_ELEVEN      ;
    char_capacity[ECC_M][NUM][691 ] = V_TWELVE      ;
    char_capacity[ECC_M][NUM][796 ] = V_THIRTEEN    ;
    char_capacity[ECC_M][NUM][871 ] = V_FOURTEEN    ;
    char_capacity[ECC_M][NUM][991 ] = V_FIFTEEN     ;
    char_capacity[ECC_M][NUM][1082] = V_SIXTEEN     ;
    char_capacity[ECC_M][NUM][1212] = V_SEVENTEEN   ;
    char_capacity[ECC_M][NUM][1346] = V_EIGHTEEN    ;
    char_capacity[ECC_M][NUM][1500] = V_NINETEEN    ;
    char_capacity[ECC_M][NUM][1600] = V_TWENTY      ;
    char_capacity[ECC_M][NUM][1708] = V_TWENTY_ONE  ;
    char_capacity[ECC_M][NUM][1872] = V_TWENTY_TWO  ;
    char_capacity[ECC_M][NUM][2059] = V_TWENTY_THREE;
    char_capacity[ECC_M][NUM][2188] = V_TWENTY_FOUR ;
    char_capacity[ECC_M][NUM][2395] = V_TWENTY_FIVE ;
    char_capacity[ECC_M][NUM][2544] = V_TWENTY_SIX  ;
    char_capacity[ECC_M][NUM][2701] = V_TWENTY_SEVEN;
    char_capacity[ECC_M][NUM][2857] = V_TWENTY_EIGHT;
    char_capacity[ECC_M][NUM][3035] = V_TWENTY_NINE ;
    char_capacity[ECC_M][NUM][3289] = V_THIRTY      ;
    char_capacity[ECC_M][NUM][3486] = V_THIRTY_ONE  ;
    char_capacity[ECC_M][NUM][3693] = V_THIRTY_TWO  ;
    char_capacity[ECC_M][NUM][3909] = V_THIRTY_THREE;
    char_capacity[ECC_M][NUM][4134] = V_THIRTY_FOUR ;
    char_capacity[ECC_M][NUM][4343] = V_THIRTY_FIVE ;
    char_capacity[ECC_M][NUM][4588] = V_THIRTY_SIX  ;
    char_capacity[ECC_M][NUM][4775] = V_THIRTY_SEVEN;
    char_capacity[ECC_M][NUM][5039] = V_THIRTY_EIGHT;
    char_capacity[ECC_M][NUM][5313] = V_THIRTY_NINE ;
    char_capacity[ECC_M][NUM][5596] = V_FORTY       ;

}

CC_Table::~CC_Table()
{}

QR::VERSION CC_Table::getSmallestVersion(QR::ECC_LEVEL lev, QR::MODE mode, int length)
{
    if(lev == UNDEFINED_LEVEL || mode == UNDEFINED_MODE){
        return UNDEFINED_VERSION;
    }
    if(mode == ALPHA_NUM && length > 4296)
        return UNDEFINED_VERSION;
    if(mode == NUM && length > 7089)
        return UNDEFINED_VERSION;

    std::map<int, QR::VERSION>::iterator it;

    it = char_capacity[lev][mode].lower_bound(length);

    if(it != char_capacity[lev][mode].end()){
        return it->second;
    }
    return UNDEFINED_VERSION;
}
