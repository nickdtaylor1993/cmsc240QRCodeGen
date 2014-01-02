//author: Georgi Lekov

#include "ECC_Table.h"

using namespace QR;

ECC_Table::ECC_Table()
{

    // updating the ecc_level and version of the entries of the table.
    for(unsigned int i = 0; i < UNDEFINED_VERSION; i++){
        for(unsigned int j = 0; j < UNDEFINED_LEVEL; j++){
            ecc_table[UNDEFINED_LEVEL*i + j].version = (VERSION)(i);
            ecc_table[UNDEFINED_LEVEL*i + j].level = (ECC_LEVEL)(j);
        }
    }

    //******************************L ECC LEVEL**************************/

    // setting the number of data words for each version and ecc_level
    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_L].num_data_words = 19;     
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_L].num_data_words = 34;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_L].num_data_words = 55;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_L].num_data_words = 80;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_L].num_data_words = 108;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_L].num_data_words = 136;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_L].num_data_words = 156;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_L].num_data_words = 194;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_L].num_data_words = 232;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_L].num_data_words = 274;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_L].num_data_words = 324;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_L].num_data_words = 370;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_L].num_data_words = 428;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_L].num_data_words = 461;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_L].num_data_words = 523;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_L].num_data_words = 589;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_L].num_data_words = 647;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_L].num_data_words = 721;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_L].num_data_words = 795;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_L].num_data_words = 861;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_L].num_data_words = 932;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_L].num_data_words = 1006;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_L].num_data_words = 1094;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_L].num_data_words = 1174;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_L].num_data_words = 1276;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_L].num_data_words = 1370;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_L].num_data_words = 1468;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_L].num_data_words = 1531;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_L].num_data_words = 1631;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_L].num_data_words = 1735;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_L].num_data_words = 1843;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_L].num_data_words = 1955;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_L].num_data_words = 2071;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_L].num_data_words = 2191;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_L].num_data_words = 2306;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_L].num_data_words = 2434;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_L].num_data_words = 2566;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_L].num_data_words = 2702;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_L].num_data_words = 2812;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_L].num_data_words = 2956;

    // setting the number of ecc words for each version and ecc_level
    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_L].num_ecc_words = 7;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_L].num_ecc_words = 10;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_L].num_ecc_words = 15;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_L].num_ecc_words = 20;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_L].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_L].num_ecc_words = 18;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_L].num_ecc_words = 20;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_L].num_ecc_words = 24;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_L].num_ecc_words = 18;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_L].num_ecc_words = 20;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_L].num_ecc_words = 24;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_L].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_L].num_ecc_words = 22;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_L].num_ecc_words = 24;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_L].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_L].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_L].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_L].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_L].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_L].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_L].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_L].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_L].num_ecc_words = 30;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_L].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_L].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_L].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_L].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_L].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_L].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_L].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_L].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_L].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_L].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_L].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_L].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_L].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_L].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_L].num_block_grpONE = 5 ;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_L].num_block_grpONE = 5 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_L].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_L].num_block_grpONE = 5 ;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_L].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_L].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_L].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_L].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_L].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_L].num_block_grpONE = 6 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_L].num_block_grpONE = 8 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_L].num_block_grpONE = 10;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_L].num_block_grpONE = 8 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_L].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_L].num_block_grpONE = 7 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_L].num_block_grpONE = 5 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_L].num_block_grpONE = 13;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_L].num_block_grpONE = 17;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_L].num_block_grpONE = 17;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_L].num_block_grpONE = 13;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_L].num_block_grpONE = 12;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_L].num_block_grpONE = 6 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_L].num_block_grpONE = 17;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_L].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_L].num_block_grpONE = 20;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_L].num_block_grpONE = 19;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_L].num_block_grpTWO = 69 ;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_L].num_block_grpTWO = 93 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_L].num_block_grpTWO = 116;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_L].num_block_grpTWO = 88 ;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_L].num_block_grpTWO = 99 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_L].num_block_grpTWO = 108;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_L].num_block_grpTWO = 121;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_L].num_block_grpTWO = 114;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_L].num_block_grpTWO = 108;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_L].num_block_grpTWO = 117;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_L].num_block_grpTWO = 112;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_L].num_block_grpTWO = 122;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_L].num_block_grpTWO = 118;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_L].num_block_grpTWO = 107;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_L].num_block_grpTWO = 115;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_L].num_block_grpTWO = 123;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_L].num_block_grpTWO = 118;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_L].num_block_grpTWO = 117;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_L].num_block_grpTWO = 116;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_L].num_block_grpTWO = 116;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_L].num_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_L].num_block_grpTWO = 116;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_L].num_block_grpTWO = 116;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_L].num_block_grpTWO = 122;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_L].num_block_grpTWO = 122;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_L].num_block_grpTWO = 123;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_L].num_block_grpTWO = 123;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_L].num_block_grpTWO = 118;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_L].num_block_grpTWO = 119;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_L].num_data_words_for_block_grpONE = 19  ;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_L].num_data_words_for_block_grpONE = 34  ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_L].num_data_words_for_block_grpONE = 55  ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_L].num_data_words_for_block_grpONE = 80  ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_L].num_data_words_for_block_grpONE = 108 ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_L].num_data_words_for_block_grpONE = 68  ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_L].num_data_words_for_block_grpONE = 78  ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_L].num_data_words_for_block_grpONE = 97  ;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_L].num_data_words_for_block_grpONE = 116 ;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_L].num_data_words_for_block_grpONE = 68  ;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_L].num_data_words_for_block_grpONE = 81  ;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_L].num_data_words_for_block_grpONE = 92  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_L].num_data_words_for_block_grpONE = 107 ;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_L].num_data_words_for_block_grpONE = 115 ;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_L].num_data_words_for_block_grpONE = 87  ;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_L].num_data_words_for_block_grpONE = 98  ;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_L].num_data_words_for_block_grpONE = 107 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_L].num_data_words_for_block_grpONE = 120 ;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_L].num_data_words_for_block_grpONE = 113 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_L].num_data_words_for_block_grpONE = 107 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_L].num_data_words_for_block_grpONE = 116 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_L].num_data_words_for_block_grpONE = 111 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_L].num_data_words_for_block_grpONE = 121 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_L].num_data_words_for_block_grpONE = 117 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_L].num_data_words_for_block_grpONE = 106 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_L].num_data_words_for_block_grpONE = 114 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_L].num_data_words_for_block_grpONE = 122 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_L].num_data_words_for_block_grpONE = 117 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_L].num_data_words_for_block_grpONE = 116 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_L].num_data_words_for_block_grpONE = 115 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_L].num_data_words_for_block_grpONE = 115 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_L].num_data_words_for_block_grpONE = 115 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_L].num_data_words_for_block_grpONE = 115 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_L].num_data_words_for_block_grpONE = 115 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_L].num_data_words_for_block_grpONE = 121 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_L].num_data_words_for_block_grpONE = 121 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_L].num_data_words_for_block_grpONE = 122 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_L].num_data_words_for_block_grpONE = 122 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_L].num_data_words_for_block_grpONE = 117 ;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_L].num_data_words_for_block_grpONE = 118 ;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_L].num_data_words_for_block_grpTWO = 2  ;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_L].num_data_words_for_block_grpTWO = 2  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_L].num_data_words_for_block_grpTWO = 1  ;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_L].num_data_words_for_block_grpTWO = 1  ;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_L].num_data_words_for_block_grpTWO = 1  ;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_L].num_data_words_for_block_grpTWO = 5  ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_L].num_data_words_for_block_grpTWO = 1  ;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_L].num_data_words_for_block_grpTWO = 4  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_L].num_data_words_for_block_grpTWO = 5  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_L].num_data_words_for_block_grpTWO = 4  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_L].num_data_words_for_block_grpTWO = 7  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_L].num_data_words_for_block_grpTWO = 5  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_L].num_data_words_for_block_grpTWO = 4  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_L].num_data_words_for_block_grpTWO = 4  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_L].num_data_words_for_block_grpTWO = 2  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_L].num_data_words_for_block_grpTWO = 4  ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_L].num_data_words_for_block_grpTWO = 10 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_L].num_data_words_for_block_grpTWO = 7  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_L].num_data_words_for_block_grpTWO = 10 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_L].num_data_words_for_block_grpTWO = 3  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_L].num_data_words_for_block_grpTWO = 0  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_L].num_data_words_for_block_grpTWO = 1  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_L].num_data_words_for_block_grpTWO = 6  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_L].num_data_words_for_block_grpTWO = 7  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_L].num_data_words_for_block_grpTWO = 14 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_L].num_data_words_for_block_grpTWO = 4  ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_L].num_data_words_for_block_grpTWO = 18 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_L].num_data_words_for_block_grpTWO = 4  ;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_L].num_data_words_for_block_grpTWO = 6  ;



    //******************************M ECC LEVEL**************************/

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_M].num_data_words = 16  ;   
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_M].num_data_words = 28  ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_M].num_data_words = 44  ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_M].num_data_words = 64  ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_M].num_data_words = 86  ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_M].num_data_words = 108 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_M].num_data_words = 124 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_M].num_data_words = 154 ;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_M].num_data_words = 182 ;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_M].num_data_words = 216 ;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_M].num_data_words = 254 ;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_M].num_data_words = 290 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_M].num_data_words = 334 ;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_M].num_data_words = 365 ;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_M].num_data_words = 415 ;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_M].num_data_words = 453 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_M].num_data_words = 507 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_M].num_data_words = 563 ;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_M].num_data_words = 627 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_M].num_data_words = 669 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_M].num_data_words = 714 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_M].num_data_words = 782 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_M].num_data_words = 860 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_M].num_data_words = 914 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_M].num_data_words = 1000;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_M].num_data_words = 1062;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_M].num_data_words = 1128;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_M].num_data_words = 1193;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_M].num_data_words = 1267;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_M].num_data_words = 1373;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_M].num_data_words = 1455;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_M].num_data_words = 1541;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_M].num_data_words = 1631;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_M].num_data_words = 1725;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_M].num_data_words = 1812;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_M].num_data_words = 1914;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_M].num_data_words = 1992;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_M].num_data_words = 2102;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_M].num_data_words = 2216;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_M].num_data_words = 2334;

    // setting the number of ecc words for each version and ecc_level
    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_M].num_ecc_words = 10;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_M].num_ecc_words = 16;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_M].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_M].num_ecc_words = 18;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_M].num_ecc_words = 24;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_M].num_ecc_words = 16;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_M].num_ecc_words = 18;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_M].num_ecc_words = 22;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_M].num_ecc_words = 22;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_M].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_M].num_ecc_words = 30;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_M].num_ecc_words = 22;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_M].num_ecc_words = 22;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_M].num_ecc_words = 24;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_M].num_ecc_words = 24;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_M].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_M].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_M].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_M].num_ecc_words = 26;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_M].num_ecc_words = 28;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_M].num_ecc_words = 28;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_M].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_M].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_M].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_M].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_M].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_M].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_M].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_M].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_M].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_M].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_M].num_block_grpONE = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_M].num_block_grpONE = 6 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_M].num_block_grpONE = 8 ;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_M].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_M].num_block_grpONE = 5 ;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_M].num_block_grpONE = 7 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_M].num_block_grpONE = 10;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_M].num_block_grpONE = 9 ;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_M].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_M].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_M].num_block_grpONE = 17;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_M].num_block_grpONE = 17;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_M].num_block_grpONE = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_M].num_block_grpONE = 6 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_M].num_block_grpONE = 8 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_M].num_block_grpONE = 19;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_M].num_block_grpONE = 22;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_M].num_block_grpONE = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_M].num_block_grpONE = 21;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_M].num_block_grpONE = 19;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_M].num_block_grpONE = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_M].num_block_grpONE = 10;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_M].num_block_grpONE = 14;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_M].num_block_grpONE = 14;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_M].num_block_grpONE = 12;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_M].num_block_grpONE = 6 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_M].num_block_grpONE = 29;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_M].num_block_grpONE = 13;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_M].num_block_grpONE = 40;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_M].num_block_grpONE = 18;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_M].num_block_grpTWO = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_M].num_block_grpTWO = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_M].num_block_grpTWO = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_M].num_block_grpTWO = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_M].num_block_grpTWO = 2 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_M].num_block_grpTWO = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_M].num_block_grpTWO = 5 ;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_M].num_block_grpTWO = 5 ;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_M].num_block_grpTWO = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_M].num_block_grpTWO = 1 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_M].num_block_grpTWO = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_M].num_block_grpTWO = 11;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_M].num_block_grpTWO = 13;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_M].num_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_M].num_block_grpTWO = 14;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_M].num_block_grpTWO = 14;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_M].num_block_grpTWO = 13;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_M].num_block_grpTWO = 4 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_M].num_block_grpTWO = 3 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_M].num_block_grpTWO = 23;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_M].num_block_grpTWO = 7 ;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_M].num_block_grpTWO = 10;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_M].num_block_grpTWO = 29;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_M].num_block_grpTWO = 23;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_M].num_block_grpTWO = 21;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_M].num_block_grpTWO = 23;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_M].num_block_grpTWO = 26;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_M].num_block_grpTWO = 34;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_M].num_block_grpTWO = 14;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_M].num_block_grpTWO = 32;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_M].num_block_grpTWO = 7 ;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_M].num_block_grpTWO = 31;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_M].num_data_words_for_block_grpONE = 16;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_M].num_data_words_for_block_grpONE = 28;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_M].num_data_words_for_block_grpONE = 44;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_M].num_data_words_for_block_grpONE = 32;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_M].num_data_words_for_block_grpONE = 43;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_M].num_data_words_for_block_grpONE = 27;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_M].num_data_words_for_block_grpONE = 31;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_M].num_data_words_for_block_grpONE = 38;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_M].num_data_words_for_block_grpONE = 36;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_M].num_data_words_for_block_grpONE = 43;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_M].num_data_words_for_block_grpONE = 50;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_M].num_data_words_for_block_grpONE = 36;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_M].num_data_words_for_block_grpONE = 37;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_M].num_data_words_for_block_grpONE = 40;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_M].num_data_words_for_block_grpONE = 41;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_M].num_data_words_for_block_grpONE = 45;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_M].num_data_words_for_block_grpONE = 43;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_M].num_data_words_for_block_grpONE = 44;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_M].num_data_words_for_block_grpONE = 41;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_M].num_data_words_for_block_grpONE = 42;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_M].num_data_words_for_block_grpONE = 47;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_M].num_data_words_for_block_grpONE = 45;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_M].num_data_words_for_block_grpONE = 47;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_M].num_data_words_for_block_grpONE = 45;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_M].num_data_words_for_block_grpONE = 45;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_M].num_data_words_for_block_grpONE = 45;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_M].num_data_words_for_block_grpONE = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_M].num_data_words_for_block_grpONE = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_M].num_data_words_for_block_grpONE = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_M].num_data_words_for_block_grpONE = 46;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_M].num_data_words_for_block_grpONE = 47;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_M].num_data_words_for_block_grpONE = 47;

    ecc_table[UNDEFINED_LEVEL*V_ONE          + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_TWO          + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_THREE        + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_FOUR         + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_FIVE         + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_SIX          + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_SEVEN        + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_EIGHT        + ECC_M].num_data_words_for_block_grpTWO = 39;
    ecc_table[UNDEFINED_LEVEL*V_NINE         + ECC_M].num_data_words_for_block_grpTWO = 37;
    ecc_table[UNDEFINED_LEVEL*V_TEN          + ECC_M].num_data_words_for_block_grpTWO = 44;
    ecc_table[UNDEFINED_LEVEL*V_ELEVEN       + ECC_M].num_data_words_for_block_grpTWO = 51;
    ecc_table[UNDEFINED_LEVEL*V_TWELVE       + ECC_M].num_data_words_for_block_grpTWO = 37;
    ecc_table[UNDEFINED_LEVEL*V_THIRTEEN     + ECC_M].num_data_words_for_block_grpTWO = 38;
    ecc_table[UNDEFINED_LEVEL*V_FOURTEEN     + ECC_M].num_data_words_for_block_grpTWO = 41;
    ecc_table[UNDEFINED_LEVEL*V_FIFTEEN      + ECC_M].num_data_words_for_block_grpTWO = 42;
    ecc_table[UNDEFINED_LEVEL*V_SIXTEEN      + ECC_M].num_data_words_for_block_grpTWO = 46;
    ecc_table[UNDEFINED_LEVEL*V_SEVENTEEN    + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_EIGHTEEN     + ECC_M].num_data_words_for_block_grpTWO = 44;
    ecc_table[UNDEFINED_LEVEL*V_NINETEEN     + ECC_M].num_data_words_for_block_grpTWO = 45;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY       + ECC_M].num_data_words_for_block_grpTWO = 42;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_ONE   + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_TWO   + ECC_M].num_data_words_for_block_grpTWO = 0 ;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_THREE + ECC_M].num_data_words_for_block_grpTWO = 48;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FOUR  + ECC_M].num_data_words_for_block_grpTWO = 46;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_FIVE  + ECC_M].num_data_words_for_block_grpTWO = 48;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SIX   + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_SEVEN + ECC_M].num_data_words_for_block_grpTWO = 46;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_EIGHT + ECC_M].num_data_words_for_block_grpTWO = 46;
    ecc_table[UNDEFINED_LEVEL*V_TWENTY_NINE  + ECC_M].num_data_words_for_block_grpTWO = 46;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY       + ECC_M].num_data_words_for_block_grpTWO = 48;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_ONE   + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_TWO   + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_THREE + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FOUR  + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_FIVE  + ECC_M].num_data_words_for_block_grpTWO = 48;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SIX   + ECC_M].num_data_words_for_block_grpTWO = 48;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_SEVEN + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_EIGHT + ECC_M].num_data_words_for_block_grpTWO = 47;
    ecc_table[UNDEFINED_LEVEL*V_THIRTY_NINE  + ECC_M].num_data_words_for_block_grpTWO = 48;
    ecc_table[UNDEFINED_LEVEL*V_FORTY        + ECC_M].num_data_words_for_block_grpTWO = 48;
}

ECC_Table::~ECC_Table() {}

VERSION ECC_Table::getVersion(int num_data, ECC_LEVEL lev)
{
    // linear search through the table to find the ecc_level and version
    // entry that match the given num_data_words and num_ecc_words
    for(unsigned int i = 0; i < sizeof(ecc_table); i++){
        if(ecc_table[i].num_data_words == num_data &&
           ecc_table[i].level  == lev)
        {
            return (VERSION)(ecc_table[i].version);
        }
    }
    return UNDEFINED_VERSION;
}
    
VERSION ECC_Table::getVersion(int num_data, int num_ecc)
{
    // linear search through the table to find the ecc_level and version
    // entry that match the given num_data_words and num_ecc_words
    for(unsigned int i = 0; i < sizeof(ecc_table); i++){
        if(ecc_table[i].num_data_words == num_data &&
           ecc_table[i].num_ecc_words  == num_ecc)
        {
            return (VERSION)(ecc_table[i].version);
        }
    }
    return UNDEFINED_VERSION;
}

ECC_LEVEL ECC_Table::getECCLevel(int num_data, int num_ecc)
{
    // linear search through the table to find the ecc_level and version
    // entry that match the given num_data_words and num_ecc_words
    for(unsigned int i = 0; i < sizeof(ecc_table); i++){
        if(ecc_table[i].num_data_words == num_data &&
           ecc_table[i].num_ecc_words  == num_ecc)
        {
            return (ECC_LEVEL)(ecc_table[i].level);
        }
    }
    return UNDEFINED_LEVEL;
}


int ECC_Table::getNumDataWords(QR::VERSION ver, QR::ECC_LEVEL lev)
{
    if(ver < UNDEFINED_VERSION && lev < UNDEFINED_LEVEL)
        return ecc_table[UNDEFINED_LEVEL*ver + lev].num_data_words;
    return 0;
}

int ECC_Table::getNumEccWords(int num_data, QR::ECC_LEVEL lev)
{
    unsigned int size_of_table = UNDEFINED_VERSION * UNDEFINED_LEVEL;
    if(lev < UNDEFINED_LEVEL){
        for(unsigned int i = 0; i < size_of_table; i++){
            if(ecc_table[i].num_data_words == num_data &&
                    ecc_table[i].level  == lev)
            {
                return (ecc_table[i].num_ecc_words);
            }
        }
    }
    return 0;
}

int ECC_Table::getNumBlocksGrpONE(QR::VERSION ver, QR::ECC_LEVEL lev)
{
    if(ver < UNDEFINED_VERSION && lev < UNDEFINED_LEVEL)
        return ecc_table[UNDEFINED_LEVEL*ver + lev].num_block_grpONE;
    return 0;
}

int ECC_Table::getNumBlocksGrpTWO(QR::VERSION ver, QR::ECC_LEVEL lev)
{
    if(ver < UNDEFINED_VERSION && lev < UNDEFINED_LEVEL)
        return ecc_table[UNDEFINED_LEVEL*ver + lev].num_block_grpTWO;
    return 0;
}

int ECC_Table::getNumWordsInBlockGrpONE(QR::VERSION ver, QR::ECC_LEVEL lev)
{
    if(ver < UNDEFINED_VERSION && lev < UNDEFINED_LEVEL)
        return ecc_table[UNDEFINED_LEVEL*ver + lev].num_data_words_for_block_grpONE;
    return 0;
}

int ECC_Table::getNumWordsInBlockGrpTWO(QR::VERSION ver, QR::ECC_LEVEL lev)
{
    if(ver < UNDEFINED_VERSION && lev < UNDEFINED_LEVEL)
        return ecc_table[UNDEFINED_LEVEL*ver + lev].num_data_words_for_block_grpTWO;
    return 0;
}
