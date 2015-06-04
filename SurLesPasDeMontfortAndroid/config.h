#ifndef DEFINES
#define DEFINES


//reglages
constexpr double SENSIBILITE_DETECTION_ZONE = 9.0;// en m
constexpr int GPS_UPDATE_INTERVAL = 10000;// en ms
constexpr int NB_MAX_QUESTION_PAR_QUIZZ = 4;

//debug
#include <QDebug>

constexpr bool BDD_VERBOSE = true;
constexpr bool FENETRE_VERBOSE = false;
constexpr bool GPS_VERBOSE = false;
constexpr bool CALCULEDISTANCE_VERBOSE = false;
constexpr bool BORNE_VERBOSE = false;


#endif // DEFINES
