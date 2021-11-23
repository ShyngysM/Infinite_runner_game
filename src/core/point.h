#ifndef POINT_H
#define POINT_H

/**
 * Ein Punkt im zweidimensionalen.
 * Beschrieben durch X- und Y-Koordinate.
 */
class Point {
public:
    Point();
    Point(int x, int y);
/**
 *  @param dx indirekte X-Verschiebung 
    @param dy indirekte Y-Verschiebung
    @param xn direkte X-Verschiebung
    @param yn direkte Y-Verschiebung
 */
    void moveBy(int dx, int dy);
    void moveTo(int xn, int yn);

    int x = 0;
    int y = 0;
}; // <-- WICHTIG, nicht vergessen

#endif




/*
    Sehr geehrter Herr Kind,
        
        ich wollte nur noch sagen, dass der Kurs war wircklich spannend und interessant.

        Sie haben uns OOP auf der C++ Sprache erfolgreich beigebracht, sodass eben ich
        es relativ gut verstanden habe.

        Der Kurs war sehr gut und studierendenfreundlich strukturiert.
        Obwohl das Ziel gar nicht so einfach war (OOP auf C++ für nicht Informatiker in einem Semester),
        hat es Ihnen gelungen, die gewisse Kenntisse in zumindest meinen Kopf hinzulegen.

        Dafür bin ich sehr dankbar und wünsche Ihnen viel Erfolg!

    Beste Grüße
    Shyngys Muratbek
    SG - EA19wA-b

*/