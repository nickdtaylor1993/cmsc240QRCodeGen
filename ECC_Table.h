//author: Georgi Lekov

#ifndef __ECC_TABLE_H__
#define __ECC_TABLE_H__

namespace QR
{
    enum MODE{
        ALPHA_NUM, 
        NUM, 
        UNDEFINED_MODE
    };

    enum ECC_LEVEL{
        ECC_L, 
        ECC_M,
        UNDEFINED_LEVEL
    };

    enum VERSION{ 
        V_ONE, 
        V_TWO,
        V_THREE,
        V_FOUR,
        V_FIVE,
        V_SIX,
        V_SEVEN,
        V_EIGHT,
        V_NINE,
        V_TEN,
        V_ELEVEN,
        V_TWELVE ,
        V_THIRTEEN ,
        V_FOURTEEN ,
        V_FIFTEEN ,
        V_SIXTEEN ,
        V_SEVENTEEN ,
        V_EIGHTEEN ,
        V_NINETEEN ,
        V_TWENTY ,
        V_TWENTY_ONE ,
        V_TWENTY_TWO ,
        V_TWENTY_THREE ,
        V_TWENTY_FOUR ,
        V_TWENTY_FIVE ,
        V_TWENTY_SIX ,
        V_TWENTY_SEVEN ,
        V_TWENTY_EIGHT ,
        V_TWENTY_NINE ,
        V_THIRTY ,
        V_THIRTY_ONE ,
        V_THIRTY_TWO ,
        V_THIRTY_THREE ,
        V_THIRTY_FOUR ,
        V_THIRTY_FIVE ,
        V_THIRTY_SIX ,
        V_THIRTY_SEVEN ,
        V_THIRTY_EIGHT ,
        V_THIRTY_NINE ,
        V_FORTY ,
        UNDEFINED_VERSION
    }; // etc

}

// for info look at
// http://www.thonky.com/qr-code-tutorial/error-correction-table/
class ECC_Table
{
    public:
        ECC_Table();
        ~ECC_Table();

        // Returns the version corresponding number of data words and ecc_level
        // important:
        // num_data_words = total words that have to be encoded using the given
        // level
        QR::VERSION getVersion(int num_data_words, QR::ECC_LEVEL lev);

        // Returns the version corresponding number of data words and number of
        // ecc words for each block !
        // important:
        // num_data_words = total words that have to be encoded using the given
        // amount of ecc_words
        QR::VERSION getVersion(int num_data_words, int num_ecc_words);

        // Returns the ecc level, given the total data codewords and number of
        // ecc words
        // important:
        // num_data_words = total words that have to be encoded using the given
        // amount of ecc_words
        QR::ECC_LEVEL getECCLevel(int num_data, int num_ecc);

        // Returns how many total data words should a QR code with the given
        // version and ecc level
        int getNumDataWords(QR::VERSION ver, QR::ECC_LEVEL lev);

        // important:
        // num_data_words = total words that have to be encoded using the given
        // amount of ecc_words
        int getNumEccWords(int num_data_words, QR::ECC_LEVEL lev);

        // Returns the number of blocks in group ONE
        int getNumBlocksGrpONE(QR::VERSION ver, QR::ECC_LEVEL lev);

        int getNumBlocksGrpTWO(QR::VERSION ver, QR::ECC_LEVEL lev);

        // Returns the number of words in group ONE
        int getNumWordsInBlockGrpONE(QR::VERSION ver, QR::ECC_LEVEL lev);

        int getNumWordsInBlockGrpTWO(QR::VERSION ver, QR::ECC_LEVEL lev);

    private:
        struct ecc_entry
        {
            QR::VERSION version;
            QR::ECC_LEVEL level;
            int num_data_words;
            int num_ecc_words;
            int num_block_grpONE;
            int num_block_grpTWO;
            int num_data_words_for_block_grpONE;
            int num_data_words_for_block_grpTWO;

            ecc_entry()
                :version(QR::UNDEFINED_VERSION),
                level(QR::UNDEFINED_LEVEL),
                num_data_words(0),
                num_ecc_words(0),
                num_block_grpONE(0),
                num_block_grpTWO(0),
                num_data_words_for_block_grpONE(0),
                num_data_words_for_block_grpTWO(0)
            {}
        };

        // the table holds all the possible pairs of version with an
        // encoding level
        ecc_entry ecc_table[QR::UNDEFINED_VERSION * QR::UNDEFINED_LEVEL];

};
#endif
