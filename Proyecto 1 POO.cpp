// Proyecto 1 POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>//Libreria para usar la función _getch() y detectar tecla pulsada por el usuario

using namespace std;

class Shape {
public:
    bool filled;
    int axisX, axisY;
    virtual void draw() = 0;

    void setAxisX(int position) {
        if (position < 0) axisX = 0;//No se aceptan números negativos
        else axisX = position;
    }

    void setAxisY(int position) {
        if (position < 0) axisY = 0;//No se aceptan números negativos
        else axisY = position;
    }
};

class Rectangle : public Shape {
public:
    int size, secondSize;//Dimensiones del rectangulo

    Rectangle(char filled, int size, int secondSize, int axisX, int axisY) {//Constructor
        if (filled == 'y' || filled == 'Y') Rectangle::filled = true;
        else Rectangle::filled = false;
        if (size < 2) Rectangle::size = 2;//La primer medida debe medir mínimo 2
        else Rectangle::size = size;
        Rectangle::secondSize = secondSize;
        Rectangle::setAxisX(axisX);
        Rectangle::setAxisY(axisY);
    }

    void draw() {//Función para dibujar el cuadrado
        for (int counter = 0; counter < size + axisY; counter++) {//Barrido de fila en fila
            for (int auxCounter = 0; auxCounter < secondSize + axisX; auxCounter++) {//Barrido de columna en columna
                if (auxCounter < axisX || counter < axisY) cout << "   ";//Se mueve a las coordendas designadas
                else {
                    if (!filled) {//Si se solicito que no estuviera rellenado
                        if (counter == axisY || counter == size + axisY - 1 || auxCounter == axisX || auxCounter == secondSize + axisX - 1) cout << " * ";//Contorno
                        else cout << "   ";//Se llena con espacios vacios
                    }
                    else cout << " * ";
                }
            }
            cout << endl;//Salto de linea
        }
    }
};

class Square : public Shape {
public:
    int size;

    Square(char filled, int size, int axisX, int axisY) {//Constructor
        if (filled == 'y' || filled == 'Y') Square::filled = true;
        else Square::filled = false;
        if (size < 2) Square::size = 2;//El cuadrado debe medir mínimo 2
        else Square::size = size;
        Square::setAxisX(axisX);
        Square::setAxisY(axisY);
    }

    void draw() {//Función para dibujar el cuadrado
        for (int counter = 0; counter < size + axisY; counter++) {//Barrido de fila en fila
            for (int auxCounter = 0; auxCounter < size + axisX; auxCounter++) {//Barrido de columna en columna
                if (auxCounter < axisX || counter < axisY) cout << "   ";//Se mueve a las coordendas designadas
                else {
                    if (!filled) {//Si se solicito que no estuviera rellenado
                        if (counter == axisY || counter == size + axisY - 1 || auxCounter == axisX || auxCounter == size + axisX - 1) cout << " * ";//Contorno
                        else cout << "   ";//Se llena con espacios vacios
                    }
                    else cout << " * ";
                }
            }
            cout << endl;//Salto de linea
        }
    }
};

class Triangle : public Shape {
public:
    int size;//Tamaños del triangulo

    Triangle(char filled, int size, int axisX, int axisY) {//Constructor
        if (filled == 'y' || filled == 'Y') Triangle::filled = true;
        else Triangle::filled = false;
        if (size < 2) Triangle::size = 2;//El triangulo debe medir mínimo 2
        else Triangle::size = size;
        Triangle::setAxisX(axisX);
        Triangle::setAxisY(axisY);
    }

    void draw() {//Función para dibujar el triangulo
        int increase = axisY * -1;//Su contraparte negativa
        for (int counter = 0; counter < size + axisY; counter++) {//Barrido de fila en fila
            for (int auxCounter = 0; auxCounter <= axisX + increase; auxCounter++) {//Barrido de columna en columna
                if (auxCounter < axisX || counter < axisY) cout << "   ";//Se mueve a las coordendas designadas
                else {
                    if (!filled) {//Si se solicito que no estuviera rellenado
                        if (counter == axisY || counter == size + axisY - 1 || auxCounter == axisX || auxCounter == increase + axisX) cout << " * ";//Contorno
                        else cout << "   ";//Se llena con espacios vacios
                    }
                    else cout << " * ";
                }
            }
            increase++;//Incremento para ir formando el triangulo
            cout << endl;//Salto de linea
        }
    }
};

void drawShape(Shape*);//Función para dibujar una figura

int main() {
    while (true) {
        int shape;//Variable para guardar respuesta del usuario conforme a que figura desea dibujar
        while (true) {
            //Instrucciones para el usuario
            cout << "Favor de escribir que figura desea dibujar\n";
            cout << "[1] Cuadrado\n";
            cout << "[2] Rectangulo\n";
            cout << "[3] Triangulo\n";
            cout << "[4] Salir\nFigura deseada: ";
            cin >> shape;

            if (shape < 1 || shape > 4) {
                system("cls");//Limpiar pantalla
                cout << "Favor de escribir una opcion valida\n\n";
            }
            else break;//Romper ciclo
        }
        if (shape == 4) break;//Romper ciclo principal

        int size, secondSize, axisX, axisY;//Propiedades de las figuras
        char filled;//Saber si la figura debe estar rellenada o no
        //Instrucciones para el usuario
        cout << "Favor de escribir el tamano de la figura (Mininimo 2): ";
        cin >> size;
        if (shape == 2) {//Se quiere realizar un rectangulo
            do {
                cout << "Las dimensiones deben ser distintas para formar un rectangulo\n";
                cout << "Favor de escribir el segundo tamano de la figura (Minimo 3): ";
                cin >> secondSize;
            } while (size == secondSize || secondSize < 3);
        }
        cout << "Favor de escribir la coordenada en X donde desea que empiece (Positivos): ";
        cin >> axisX;
        cout << "Favor de escribir la coordenada en Y donde desea que empiece (Positivos): ";
        cin >> axisY;
        do {
            cout << "\nDesea que la figura este rellenada? [y/n]: ";
            cin >> filled;
        } while (filled != 'y' && filled != 'Y' && filled != 'n' && filled != 'N');
        system("cls");//Limpiar pantalla

        switch (shape) {
        case 1: {
            Square square(filled, size, axisX, axisY);//Creamos el cuadrado
            drawShape(&square);//Lo mandamos a dibujar
            break;
            }
        case 2: {
            Rectangle rectangle(filled, size, secondSize, axisX, axisY);//Creamos el rectangulo
            drawShape(&rectangle);//Lo mandamos a dibujar
            break;
            }
        case 3: {
            Triangle triangle(filled, size, axisX, axisY);//Creamos el triangulo
            drawShape(&triangle);//Lo mandamos a dibujar
            break;
            }
        }
        system("cls");//Limpiar pantalla
    }
}

void drawShape(Shape* shape) {//Utilizamos un puntero al objeto hijo que se nos proporcione
    shape->draw();
    while (true) {
        char key = _getch();//Obtener tecla pulsada por el usuario
        switch (key) {
        case 27:
            return;//Salirse del ciclo con "Esc"
            break;
        case 119://'w'
        case 87://'W'
            shape->setAxisY(shape->axisY - 1);//Mover hacia arriba
            break;
        case 115://'s'
        case 83://'S'
            shape->setAxisY(shape->axisY + 1);//Mover hacia abajo
            break;
        case 97://'a'
        case 65://'A'
            shape->setAxisX(shape->axisX - 1);//Mover hacia la izquierda
            break;
        case 100://'d'
        case 68://'D'
            shape->setAxisX(shape->axisX + 1);//Mover hacia la izquierda
            break;
        }
        system("cls");//Limpiar pantalla
        shape->draw();
    }
}
