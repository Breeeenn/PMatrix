

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main()
{
    // crea una ventana especial para dibujo
    RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setPosition(sf::Vector2i(300, 70)); //Posición de ventana
    window.setSize(sf::Vector2u(800, 500)); //Tamaño de la ventana
    window.setTitle("MATRIX PROYECT");//Le pone titulo a la ventana
    bool focus = window.hasFocus(); //foco?
    window.setVerticalSyncEnabled(true); /** la aplicación se ejecutará a la misma frecuencia
    que la frecuencia de actualización del monitor.**/

    // //Sirve para visualizar una ventana
    while (window.isOpen())
    {
        // Verifica cualquier evento que ocurra
        Event event;
        while (window.pollEvent(event))
        {
            // Cierra la ventana cuando se solicita
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /** Limpia la ventana con color negro nos ayudará a que
        los fotogramas no se nos amontonen **/
        window.clear(sf::Color::Green);

        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
