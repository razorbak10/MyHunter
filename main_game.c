/*
** EPITECH PROJECT, 2019
** de
** File description:
** de
*/
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window/Export.h>
#include <stdio.h>

char *nb_tochar(int i)
{
    int len = 0;
    int neg = 0;
    if (i == 0)
        len++;
    for (int k = i; k != 0; k = k/10, len++);
    if (i < 0) {
        len++;
        neg = 1;
        i = i * -1;
    }
    char *c = malloc(sizeof(char) * (len + 1));
    c[len] = '\0';
    len--;
    for (; len >= 0; len--) {
        c[len] = i % 10 + 48;
        i = i / 10;
    }
    if (neg)
        c[0] = '-';
    return (c);
}

int My_Hunter(sfRenderWindow *window)
{
    int bonus = 0;
    int lifee = 3;
    int niveau2 = 0;
    int timer = 0;
    int scorre = 0;
    sfTime time;
    sfTexture *wallpaper;
    sfTexture *ballon;
    sfTexture *ballon2;
    sfTexture *ballon3;
    sfTexture *ballonbleu;
    sfTexture *ballonbleu2;
    sfTexture *ballonbleu3;
    sfTexture *ballonnblack;
    sfTexture *ballonnblack2;
    sfTexture *ballonnblack3;
    sfTexture *lapin;
    sfTexture *lapin2;
    sfTexture *lapin3;
    sfTexture *lapin4;
    sfTexture *lapin5;
    sfTexture *ballon_dead;
    sfSprite *wallpaper_sprite;
    sfSprite *ballon_sprite;
    sfSprite *ballonblue_sprite;
    sfSprite *ballonblack_sprite;
    sfSprite *lapin_sprite;
    sfVector2f vector = {0, 400};
    sfVector2f vector2 = {-500 , 500};
    sfVector2f vector_lapin = {-400 , 700};
    sfVector2f vector_black = {-400 , 400};
    sfVector2f souris2;
    sfVector2f scoreposition = {0, -100};
    sfVector2f scorevrai = {300, -100};
    sfVector2f lifeposition = {1300, -100};
    sfVector2f lifepose_conp ={1500, -100};
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create();
    sfClock *clock4 = sfClock_create();
    sfClock *clock_sprite = sfClock_create();
    sfClock *clock_sprite2 = sfClock_create();
    sfClock *clock_sprite3 = sfClock_create();
    sfClock *clock_lapin = sfClock_create();
    sfText *score;
    sfText *score2;
    sfText *life;
    sfText *life2;
    sfFont *font;

    wallpaper = sfTexture_createFromFile("texture/mapvrai.png", NULL);

    ballon = sfTexture_createFromFile("texture/ballonn3_ar.png", NULL);
    ballon2 = sfTexture_createFromFile("texture/ballonn3.png", NULL);
    ballon3 = sfTexture_createFromFile("texture/ballonn3_der.png", NULL);

    ballon_dead = sfTexture_createFromFile("texture/ballon1_dead.png", NULL);

    ballonbleu = sfTexture_createFromFile("texture/ballonblue_ar.png", NULL);
    ballonbleu2 = sfTexture_createFromFile("texture/ballon_blue.png", NULL);
    ballonbleu3 = sfTexture_createFromFile("texture/ballonnblue_der.png", NULL);

    ballonnblack = sfTexture_createFromFile("texture/ballonblack.png",NULL);
    ballonnblack2 = sfTexture_createFromFile("texture/ballon_black.png",NULL);
    ballonnblack3 = sfTexture_createFromFile("texture/ballonnblack_der.png",NULL);

    lapin = sfTexture_createFromFile("texture/lapinV.png",NULL);
    lapin2 = sfTexture_createFromFile("texture/lapinv2.png",NULL);
    lapin3 = sfTexture_createFromFile("texture/lapinV3.png",NULL);
    lapin4 = sfTexture_createFromFile("texture/lapinv4.png",NULL);
    lapin5 = sfTexture_createFromFile("texture/lapinv5.png",NULL);

    font = sfFont_createFromFile("police/police.otf");

    wallpaper_sprite = sfSprite_create();

    ballon_sprite = sfSprite_create();
    ballonblue_sprite = sfSprite_create();
    ballonblack_sprite = sfSprite_create();
    lapin_sprite = sfSprite_create();


    score = sfText_create();
    sfText_setString(score, "Score :");
    sfText_setPosition(score,scoreposition);
    sfText_setFont(score,font);
    sfText_setCharacterSize(score,200);
    sfText_setColor(score,sfRed);

    score2 = sfText_create();
    sfText_setString(score2,nb_tochar(scorre));
    sfText_setPosition(score2,scorevrai);
    sfText_setFont(score2,font);
    sfText_setCharacterSize(score2,200);
    sfText_setColor(score2,sfRed);

    life = sfText_create();
    sfText_setString(life, "Life :");
    sfText_setPosition(life,lifeposition);
    sfText_setFont(life,font);
    sfText_setCharacterSize(life,200);
    sfText_setColor(life,sfRed);

    life2 = sfText_create();
    sfText_setString(life2,nb_tochar(lifee));
    sfText_setPosition(life2,lifepose_conp);
    sfText_setFont(life2,font);
    sfText_setCharacterSize(life2,200);
    sfText_setColor(life2,sfRed);





    sfSprite_setTexture(wallpaper_sprite, wallpaper, sfTrue);

    sfSprite_setTexture(ballonblue_sprite, ballonbleu,sfTrue);
    sfSprite_setPosition(ballonblue_sprite,vector2);

    sfSprite_setTexture(ballon_sprite, ballon, sfTrue);
    sfSprite_setPosition(ballon_sprite, vector);

    sfSprite_setTexture(ballonblack_sprite, ballonnblack,sfTrue);
    sfSprite_setPosition(ballonblack_sprite,vector_black);

    sfSprite_setTexture(lapin_sprite,lapin,sfTrue);
    sfSprite_setPosition(lapin_sprite,vector_lapin);



    while (sfRenderWindow_isOpen(window)) {
        
        
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 200){
            sfSprite_setTexture(ballon_sprite,ballon,sfTrue);
            }
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 400){
            sfSprite_setTexture(ballon_sprite,ballon2,sfTrue);
            }
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 600){
            sfSprite_setTexture(ballon_sprite,ballon3,sfTrue);
            sfClock_restart(clock);
            }
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock_sprite)) > 1) {
            vector.x = vector.x + 1;
            sfClock_restart(clock_sprite);
            }
        
            if (niveau2 >= 10){
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock2)) > 200){
                sfSprite_setTexture(ballonblue_sprite,ballonbleu,sfTrue);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock2)) > 400){
                sfSprite_setTexture(ballonblue_sprite,ballonbleu2,sfTrue);
                } 
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock2)) > 600){
                sfSprite_setTexture(ballonblue_sprite,ballonbleu3,sfTrue);
                sfClock_restart(clock2);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock_sprite2)) > 1){
                vector2.x = vector2.x + 2;
                sfClock_restart(clock_sprite2);
                }
            }
            if (niveau2 >= 15) {
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock4)) > 200){
                sfSprite_setTexture(ballonblack_sprite,ballonnblack,sfTrue);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock4)) > 400){
                sfSprite_setTexture(ballonblack_sprite,ballonnblack2,sfTrue);
                } 
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock4)) > 600){
                sfSprite_setTexture(ballonblack_sprite,ballonnblack3,sfTrue);
                sfClock_restart(clock4);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock_sprite3)) > 0.5){
                vector_black.x = vector_black.x + 3;
                sfClock_restart(clock_sprite3);
                }


            }
            if (bonus >= 2) {
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock3)) > 200){
                sfSprite_setTexture(lapin_sprite,lapin,sfTrue);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock3)) > 400){
                sfSprite_setTexture(lapin_sprite,lapin2,sfTrue);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock3)) > 600){
                sfSprite_setTexture(lapin_sprite,lapin3,sfTrue);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock3)) > 800){
                sfSprite_setTexture(lapin_sprite,lapin4,sfTrue);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock3)) > 1000){
                sfSprite_setTexture(lapin_sprite,lapin5,sfTrue);
                sfClock_restart(clock3);
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock_lapin)) > 0.01) {
                    vector_lapin.x = vector_lapin.x + 10;
                    sfClock_restart(clock_lapin);
                }

            }

        if (vector.x >= 2000) {
            vector.x = -200;
            lifee = lifee - 1;
             sfText_setString(life2,nb_tochar(lifee));
        }
        if (vector2.x >= 2000 ){
            vector2.x = -200;
            lifee = lifee - 1;
             sfText_setString(life2,nb_tochar(lifee));
        }
        if (vector_black.x >= 2000) {
            vector_black.x = -200;
            lifee = lifee - 1;
             sfText_setString(life2,nb_tochar(lifee));
        }
        if (vector_lapin.x >= 2000)
            vector_lapin.x = -2000;
          sfSprite_setPosition(lapin_sprite,vector_lapin);
          sfSprite_setPosition(ballonblue_sprite,vector2);
          sfSprite_setPosition(ballonblack_sprite, vector_black);
          sfSprite_setPosition(ballon_sprite,vector);
          sfVector2i souris = sfMouse_getPositionRenderWindow(window);
            souris2.x = (float)souris.x;
            souris2.y = (float)souris.y;

         while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type = sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape) || sfKeyboard_isKeyPressed(sfKeyLControl) && sfKeyboard_isKeyPressed(sfKeyC)) {
                sfRenderWindow_close(window);
            }
            else if (sfMouse_isButtonPressed(sfMouseLeft)) {
                if (souris2.x >= vector.x && souris2.x <= vector.x +136 && souris2.y >= vector.y && souris2.y <= vector.y +231){
                    vector.x = -500;
                    vector.y = rand() % 800;
                    niveau2 = niveau2 + 1;
                    bonus = bonus + 1;
                    scorre = scorre + 15;
                    sfText_setString(score2,nb_tochar(scorre));
                }
                if (souris2.x >= vector2.x && souris2.x <= vector2.x +136 && souris2.y >= vector2.y && souris2.y <= vector2.y +231)
                {
                    vector2.x = -500;
                    vector2.y = rand() % 500;
                    scorre = scorre +25;
                    sfText_setString(score2,nb_tochar(scorre));
                }
                if (souris2.x >= vector_black.x && souris2.x <= vector_black.x +136 && souris2.y >= vector_black.y && souris2.y <= vector_black.y +231)
                {
                    vector_black.x = -500;
                    vector_black.y = rand() % 500;
                    scorre =scorre + 50;
                    sfText_setString(score2,nb_tochar(scorre));
                }
                if (souris2.x >= vector_lapin.x && souris2.x <= vector_lapin.x +79 && souris2.y >= vector_lapin.y && souris2.y <= vector_lapin.y +138)
                {
                    vector_lapin.x = -10000;
                    scorre = scorre + 3000;
                    sfText_setString(score2,nb_tochar(scorre));

                }
                sfText_setString(life2,nb_tochar(lifee));

                if (event.type = sfEvtClosed || lifee == 0){
                    My_Hunter(window);
                    lifee =  3;
                    sfText_setString(life2,nb_tochar(lifee));

                }

                

            }

        }
        sfRenderWindow_drawSprite(window, wallpaper_sprite, NULL);
        sfRenderWindow_drawSprite(window, ballon_sprite, NULL);
        sfRenderWindow_drawSprite(window, ballonblue_sprite,NULL);
        sfRenderWindow_drawSprite(window,ballonblack_sprite,NULL);
        sfRenderWindow_drawSprite(window, lapin_sprite,NULL);
        sfRenderWindow_drawText(window,score,NULL);
        sfRenderWindow_drawText(window,score2,NULL);
        sfRenderWindow_drawText(window,life,NULL);
        sfRenderWindow_drawText(window,life2,NULL);
        sfRenderWindow_display(window);
        
       
    }   


}
