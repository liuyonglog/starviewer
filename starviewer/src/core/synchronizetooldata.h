/***************************************************************************
 *   Copyright (C) 2005-2007 by Grup de Gràfics de Girona                  *
 *   http://iiia.udg.es/GGG/index.html?langu=uk                            *
 *                                                                         *
 *   Universitat de Girona                                                 *
 ***************************************************************************/
#ifndef UDGSYNCHRONIZETOOLDATA_H
#define UDGSYNCHRONIZETOOLDATA_H

#include <tooldata.h>

namespace udg {

class Q2DViewer;

/**
Classe per guardar les dades de la tool de sincronització.

	@author Grup de Gràfics de Girona  ( GGG ) <vismed@ima.udg.es>
*/
class SynchronizeToolData : public ToolData
{
Q_OBJECT
public:
    SynchronizeToolData();

    ~SynchronizeToolData();

    /// Obtenir l'increment de llesca
    int getIncrement();

    /// Obtenir el valor del window level
    double getWindow();
    double getLevel();

    /// Obtenir el factor de zoom
    double getZoomFactor();

public slots:

    /// Per canviar les dades de sincronitzacio de llesques
    void setIncrement( int value );

    /// Per canviar les dades de sincronitzacio del window level
    void setWindowLevel( double window, double level );

    /// Per canviar les dades de sincronitzacio del factor de zoom
    void setZoomFactor( double factor );

signals:

    /// Signal que s'emet quan les dades de l'increment de llesca canvien
    void sliceChanged();

    /// Signal que s'emet quan les dades de window level canvien
    void windowLevelChanged();

    /// Signal que s'emet quan el factor de zoom canvia
    void zoomFactorChanged();

private:

    /// Dades per la sincronització de l'slicing
    int m_increment;

    /// Dades per la sincronització del window level
    double m_window;
    double m_level;

    /// Dades per la sincronització del zoom
    double m_zoomFactor;
};

}

#endif
