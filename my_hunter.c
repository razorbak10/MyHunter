/*
** EPITECH PROJECT, 2019
** hunter
** File description:
** 
*/

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdlib.h>
/*
** EPITECH PROJECT, 2019
** hunter
** File description:
** 
*/

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdlib.h>

int main(int ac , char **av)
{
    check_help(ac ,av);
    sfVideoMode mode = {1920,1080,32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfTexture* button_play;
    sfTexture* button_close;
    sfSprite* sprite_button;
    sfSprite* sprite;
    sfFont* font;
    sfText* text;
    sfRectangleShape* play;
    sfRectangleShape* close;
    sfMusic* music;
    sfEvent event;
    sfBool left;
    sfVector2f local_plays = {750, 400};
    sfVector2f position_close = {1700, 0};
    sfVector2f grandeur_close = {200, 150};
    sfVector2f position2;

    window = sfRenderWindow_create(mode, "Happy Hunter", sfResize | sfClose, NULL);

    texture = sfTexture_createFromFile("texture/la.png", NULL);
    button_play = sfTexture_createFromFile("texture/bouton_play1.png",NULL);
    
    sprite = sfSprite_create();
    sprite_button = sfSprite_create();
    int closed = 0;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite_button, button_play,sfTrue);
    sfSprite_setPosition(sprite_button,local_plays);

    music = sfMusic_createFromFile("song/happy2.ogg");

    sfMusic_play(music);

    while (sfRenderWindow_isOpen(window))
    {
       sfVector2i position = sfMouse_getPositionRenderWindow(window);
        position2.x = (float)position.x;
        position2.y = (float)position.y;
       
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type = sfEvtClosed || closed == 1 ||  sfKeyboard_isKeyPressed(sfKeyEscape) || sfKeyboard_isKeyPressed(sfKeyLControl) && sfKeyboard_isKeyPressed(sfKeyC)) {
                sfRenderWindow_close(window);
            }
            if (event.type = sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEnter)) {
                My_Hunter(window);
            }
            else if (sfMouse_isButtonPressed(sfMouseLeft)) {
                if (position2.x >= local_plays.x && position2.x <= local_plays.x +450 && position2.y >= local_plays.y && position2.y <= local_plays.y +100) {
                    My_Hunter(window);
                }
            }

        }
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, sprite, NULL); 

    }
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite_button);
    sfRenderWindow_destroy(window);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
void my_putchar(char c){
    write(1, &c ,1);
}

void check_help(int ac , char **av)
{
    if (ac < 2 )
    return(0);
    for (int i = 1; i <= ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'h'){
            my_putstr("les regles du jeux tire sur les ballons pour avoir le plus de point\n");
            return(0);
        }  
    }
}
