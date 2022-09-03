#include <iostream>
#include <allegro.h>
#include <conio.h>
#include <cmath>

using namespace std;
////////
///////
//Funciones de los niveles 1, 2, 3, 4

void rotar(float &x, float&y, float cx, float cy, float da);
void pintar_nave(float cx, float cy, BITMAP *buffer); 
void mover_nave(float &cx, float &cy, float &vx, float &vy);
void aceleracion(float da, float &vx, float &vy);
void medidor_combustible(bool gastar_combustible, float &combustible, BITMAP *buffer);
void pintar_motor(float da, float cx, float cy, BITMAP *buffer);
void pintar_nivel( int num_nivel, BITMAP *buffer );
void explosion(float cx, float cy, BITMAP * buffer, int num_nivel);
void explosion_laberinto(float camino_x, float camino_y, BITMAP * buffer, int num_nivel);
bool aterrizar(float cx, float cy, float vx, float vy, BITMAP * buffer, int num_nivel);
void avanzar_nivel(float &cx, float &cy, float &vx, float &vy, int &num_nivel , float &combustible, BITMAP *buffer);
bool choque_triangulo(float x1, float y1, float x2, float y2, float p1x, float p1y, float p2x, float p2, string tipo_triangulo);
bool choque_nave(int num_nivel, float cx, float cy);


//Funciones del nivel 5

void rotar5(float &x, float &y, float cx5, float cy5, float da);
void pintar_nave5(float cx5 , float cy5, BITMAP *buffer);
void caida_nave5(float &cx5, float &cy5, float &vx5, float &vy5);
void estrellas_1(float e1x, float e1y, BITMAP *buffer); 
void caida_estrellas_1(float &e1x, float &e1y, float &o1x, float &o1y);
void estrellas_2(float e2x, float e2y, BITMAP *buffer); 
void caida_estrellas_2(float &e2x, float &e2y, float &o2x, float &o2y);
void estrellas_3(float e3x, float e3y, BITMAP *buffer); 
void caida_estrellas_3(float &e3x, float &e3y, float &o3x, float &o3y);
void estrellas_4(float e4x, float e4y, BITMAP *buffer); 
void caida_estrellas_4(float &e4x, float &e4y, float &o4x, float &o4y);
void estrellas_5(float e5x, float e5y, BITMAP *buffer);
void caida_estrellas_5(float &e5x, float &e5y, float &o5x, float &o5y);
void estrellas_6(float e6x, float e6y, BITMAP *buffer); 
void caida_estrellas_6(float &e6x, float &e6y, float &o6x, float &o6y);
void estrellas_7(float e7x, float e7y, BITMAP *buffer); 
void caida_estrellas_7(float &e7x, float &e7y, float &o7x, float &o7y);
void estrellas_8(float e8x, float e8y, BITMAP *buffer); 
void caida_estrellas_8(float &e8x, float &e8y, float &o8x, float &o8y);
void meteoritos_1(float m1x, float m1y, BITMAP *buffer); 
void caida_meteoritos_1(float &m1x, float &m1y, float &n1x, float &n1y);
void meteoritos_2(float m2x, float m2y, BITMAP *buffer); 
void caida_meteoritos_2(float &m2x, float &m2y, float &n2x, float &n2y);
void meteoritos_3(float m3x, float m3y, BITMAP *buffer); 
void caida_meteoritos_3(float &m3x, float &m3y, float &n3x, float &n3y);
void meteoritos_4(float m4x, float m4y, BITMAP *buffer); 
void caida_meteoritos_4(float &m4x, float &m4y, float &n4x, float &n4y);
void meteoritos_5(float m5x, float m5y, BITMAP *buffer); 
void caida_meteoritos_5(float &m5x, float &m5y, float &n5x, float &n5y);
void meteoritos_6(float m6x, float m6y, BITMAP *buffer); 
void caida_meteoritos_6(float &m6x, float &m6y, float &n6x, float &n6y);
void meteoritos_7(float m7x, float m7y, BITMAP *buffer); 
void caida_meteoritos_7(float &m7x, float &m7y, float &n7x, float &n7y);
void meteoritos_8(float m8x, float m8y, BITMAP *buffer); 
void caida_meteoritos_8(float &m8x, float &m8y, float &n8x, float &n8y);
void meteoritos_9(float m9x, float m9y, BITMAP *buffer); 
void caida_meteoritos_9(float &m9x, float &m9y, float &n9x, float &n9y);
void meteoritos_10(float m10x, float m10y, BITMAP *buffer); 
void caida_meteoritos_10(float &m10x, float &m10y, float &n10x, float &n10y);
void aceleracion5(float da, float &vx5, float &vy5);
void tiempo(bool tiempo_corriendo, float &tiempo_restante, BITMAP *buffer);
void explosion5(float cx5, float cy5, BITMAP *buffer, int num_nivel);
void vida1(float vida1_x , float vida1_y , BITMAP *buffer);
void vida2(float vida2_x , float vida2_y , BITMAP *buffer);
void vida3(float vida3_x , float vida3_y , BITMAP *buffer);
void barra_1(float &punto_inicio_1_x, float &punto_inicio_1_y, float &punto_final_1_x, float &punto_final_1_y, BITMAP *buffer);
void caida_barra_1(float &punto_inicio_1_x, float &punto_inicio_1_y, float &punto_final_1_x, float &punto_final_1_y);
void barra_2(float &punto_inicio_2_x, float &punto_inicio_2_y, float &punto_final_2_x, float &punto_final_2_y, BITMAP *buffer);
void caida_barra_2(float &punto_inicio_2_x, float &punto_inicio_2_y, float &punto_final_2_x, float &punto_final_2_y);
void barra_3(float &punto_inicio_3_x, float &punto_inicio_3_y, float &punto_final_3_x, float &punto_final_3_y, BITMAP *buffer);
void caida_barra_3(float &punto_inicio_3_x, float &punto_inicio_3_y, float &punto_final_3_x, float &punto_final_3_y);

///////////////////////////////////////////////////////////////


int main(){

	allegro_init();
	install_keyboard(); 
	install_mouse();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1200 , 700 , 0 , 0 ); 
	BITMAP *buffer  = create_bitmap(1200, 700);

	BITMAP *fondo1 = load_bitmap("FONDO1.bmp", NULL); 
	BITMAP *fondo2 = load_bitmap("FONDO2.bmp", NULL); 
	BITMAP *fondo3 = load_bitmap("FONDO3.bmp", NULL); 
	BITMAP *cursor = load_bitmap("cursor.bmp", NULL); 
	BITMAP *espacio = load_bitmap("espacio.bmp", NULL);
	
		
	bool salida = false;
	bool nodo = false;
	bool salida_menu2 = false;
	bool salida_niveles= false;
	
	bool nivel1_seleccionado=true;
	bool nivel2_seleccionado=true;
	bool nivel3_seleccionado=true;
	bool nivel4_seleccionado=true;
	bool nivel5_seleccionado=true;
	
	int num_nivel;
	
	while(!salida){
		
		if (mouse_x > 823 && mouse_x < 1151 && mouse_y > 239 && mouse_y < 281){
			blit(fondo2, buffer, 0, 0, 0, 0, 1200, 700 );
			if(mouse_b & 1){
				salida = true;
			}
			
		}else if(mouse_x > 39 && mouse_x < 309 && mouse_y > 27 && mouse_y < 41){
			blit(fondo3, buffer, 0, 0, 0, 0, 1200, 700);
			if(mouse_b & 1 ){
				
				salida = false;				
			}blit(espacio, buffer, 0, 0, 0, 0, 1200, 700);						
		}else blit(fondo1, buffer, 0, 0, 0, 0, 1200, 700);
		
		masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 64, 64);
		blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
	}
	
	//SELECCION MODO DE JUEGO
	
	BITMAP *menu2 = load_bitmap("menu2.bmp", NULL);
	BITMAP *menu2normal = load_bitmap("menu2_normal.bmp", NULL);
	BITMAP *menu2seleccion = load_bitmap("menu2_seleccion.bmp", NULL);
	
	bool seleccionar_menu=false;
	
	while(!salida_menu2){
		
		if (mouse_x > 46 && mouse_x < 300 && mouse_y > 305 && mouse_y < 484){
			blit(menu2normal, buffer, 0, 0, 0, 0, 1200, 700 );
			if(mouse_b & 1){
				salida_menu2 = true;
			}			
		}else if(mouse_x > 862 && mouse_x < 1183 && mouse_y > 315 && mouse_y < 496){
			blit(menu2seleccion, buffer, 0, 0, 0, 0, 1200, 700);
			if(mouse_b & 1 ){	
				seleccionar_menu=true;			
				salida_menu2 = true;							
			} 
		}else blit(menu2, buffer, 0, 0, 0, 0, 1200, 700);
		masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 64, 64);
		blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
	}
	
	
	///////////////////////////////////////////////////////////////////////////////
	
	//SELECCION DE NIVELES
	
	if(seleccionar_menu==true){
		
		BITMAP *niveles = load_bitmap("niveles.bmp", NULL);
		BITMAP *nivel1 = load_bitmap("nivel1.bmp", NULL);
		BITMAP *nivel2 = load_bitmap("nivel2.bmp", NULL);
		BITMAP *nivel3 = load_bitmap("nivel3.bmp", NULL);
		BITMAP *nivel4 = load_bitmap("nivel4.bmp", NULL);
		BITMAP *nivel5 = load_bitmap("nivel5.bmp", NULL);
	
		while(!salida_niveles){
			
			if (mouse_x > 165 && mouse_x < 374 && mouse_y > 78 && mouse_y < 125){
				blit(nivel1, buffer, 0, 0, 0, 0, 1200, 700 );
				if(mouse_b & 1){
					
					nivel1_seleccionado=true;
					nivel2_seleccionado=false;
					nivel3_seleccionado=false;
					nivel4_seleccionado=false;
					nivel5_seleccionado=false;
					
					salida_niveles = true;
				}			
			}else if(mouse_x > 552 && mouse_x < 765 && mouse_y > 158 && mouse_y < 206){
				blit(nivel2, buffer, 0, 0, 0, 0, 1200, 700);
				if(mouse_b & 1 ){
				
					nivel1_seleccionado=false;
					nivel2_seleccionado=true;
					nivel3_seleccionado=false;
					nivel4_seleccionado=false;
					nivel5_seleccionado=false;
									
					salida_niveles = true;				
				}		
			}else if(mouse_x > 865 && mouse_x < 1080 && mouse_y > 350 && mouse_y < 399){
				blit(nivel3, buffer, 0, 0, 0, 0, 1200, 700);
				if(mouse_b & 1 ){	
				
					nivel1_seleccionado=false;
					nivel2_seleccionado=false;
					nivel3_seleccionado=true;
					nivel4_seleccionado=false;
					nivel5_seleccionado=false;
							
					salida_niveles = true;				
				}		
			}else if(mouse_x > 132 && mouse_x < 348 && mouse_y > 423 && mouse_y < 469){
				blit(nivel4, buffer, 0, 0, 0, 0, 1200, 700);
				if(mouse_b & 1 ){
				
					nivel1_seleccionado=false;
					nivel2_seleccionado=false;
					nivel3_seleccionado=false;
					nivel4_seleccionado=true;
					nivel5_seleccionado=false;
								
					salida_niveles = true;				
				}		
			}else if(mouse_x > 628 && mouse_x < 842 && mouse_y > 563 && mouse_y < 611){
				blit(nivel5, buffer, 0, 0, 0, 0, 1200, 700);
				if(mouse_b & 1 ){	
				
					nivel1_seleccionado=false;
					nivel2_seleccionado=false;
					nivel3_seleccionado=false;
					nivel4_seleccionado=false;
					nivel5_seleccionado=true;
							
					salida_niveles = true;				
				}		
			}else blit(niveles, buffer, 0, 0, 0, 0, 1200, 700);
			
			masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 64, 64);
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
		}	
	}
	
	
	/////////////////////////////////////////////////////
	
	//NIVEL 1
	
	if(nivel1_seleccionado==true){	
		
		float nivel1_carga=0;
		BITMAP *stage1 = load_bitmap("stage1.bmp", NULL);
		BITMAP *stage1_2 = load_bitmap("stage1_2.bmp", NULL);
		BITMAP *stage1_3 = load_bitmap("stage1_3.bmp", NULL);
		while(nivel1_carga<=1160){
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			if((nivel1_carga>=0 && nivel1_carga<50)||(nivel1_carga>=150 && nivel1_carga<200)||(nivel1_carga>=300 && nivel1_carga<350) || (nivel1_carga>=450 && nivel1_carga<500) || (nivel1_carga>=600 && nivel1_carga<650) || (nivel1_carga>=750 && nivel1_carga<800) || (nivel1_carga>=900 && nivel1_carga<950) || (nivel1_carga>=1050 && nivel1_carga<1100)){
				blit(stage1, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel1_carga>=50 && nivel1_carga<100)||(nivel1_carga>=200 && nivel1_carga<250) || (nivel1_carga>=350 && nivel1_carga<400) || (nivel1_carga>=500 && nivel1_carga<550) || (nivel1_carga>=650 && nivel1_carga<700) || (nivel1_carga>=800 && nivel1_carga<850) || (nivel1_carga>=950 && nivel1_carga<1000) || (nivel1_carga>=1100 && nivel1_carga<1150)){
				blit(stage1_2, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel1_carga>=100 && nivel1_carga<150)||(nivel1_carga>=250 && nivel1_carga<300) || (nivel1_carga>=400 && nivel1_carga<450) || (nivel1_carga>=550 && nivel1_carga<600) || (nivel1_carga>=700 && nivel1_carga<750) || (nivel1_carga>=850 && nivel1_carga<900) || (nivel1_carga>=1000 && nivel1_carga<1050)){
				blit(stage1_3, buffer, 0, 0, 0, 0, 1200, 700);
			}										
			rectfill(buffer, 20, 630, 20+nivel1_carga, 680, 0xFF0000 );
			nivel1_carga=nivel1_carga+0.3;
		}
		
		int num_nivel = 1;

		float camino_x, camino_y;
		float cx, cy;
		float vx=0, vy=0;
		
		float x1y, x2y, p1y, p2y;
		if( num_nivel ==1){
			cx= 60;
			cy= 60;	
		}
	
		if( num_nivel ==2){
			cx= 60;
			cy= 600;	
		}
		
		if( num_nivel ==3){
			cx= 60;
			cy= 60;	
		}
		
		if( num_nivel ==4){
			cx= 60;
			cy= 600;		
		}
		
		float combustible= 100, Timme = 500;  
		
		float combustible_nivel=200;
	
	
		while( /*!key[KEY_ESC] && !Game_Over(cx, cy, buffer, num_nivel) &&*/ !aterrizar(cx, cy, vx, vy, buffer, num_nivel) ){
			bool gastar_combustible = false;
			clear_to_color(buffer,0x000000); // se limpia el buffer
			pintar_nivel(num_nivel, buffer);			
			
			pintar_nave(cx, cy, buffer); // pintar el buffer 
			mover_nave(cx,cy,vx,vy);	
				
			if(key[KEY_W] && combustible_nivel > 0){
				aceleracion(0, vx, vy);  //cuando el ang es igual a cero la aceleracion es hacia arrriba
				
				line(buffer, cx-15,cy+40,cx-10,cy+50, 0xFFD500);
				line(buffer, cx-10,cy+50,cx-5,cy+45, 0xFFD500);
				line(buffer, cx-5,cy+45,cx,cy+60, 0xFFD500);
				line(buffer, cx+15,cy+40,cx+10,cy+50, 0xFFD500);
				line(buffer, cx+10,cy+50,cx+5,cy+45, 0xFFD500);
				line(buffer, cx+5,cy+45,cx,cy+60, 0xFFD500);
				
			    //pintar_motor(0, cx, cy, buffer);
				gastar_combustible = true;
			
				combustible_nivel=combustible_nivel-0.9;				
		
			}
			
			if(key[KEY_D] && combustible_nivel > 0){
				aceleracion(-90, vx, vy);
				
				line(buffer, cx-35,cy+10,cx-40,cy+25, 0xFFD500);
				line(buffer, cx-40,cy+25,cx-35,cy+30, 0xFFD500);
				line(buffer, cx-35,cy+30,cx-40,cy+45, 0xFFD500);
				line(buffer, cx-40,cy+45,cx-25,cy+40, 0xFFD500);
				line(buffer, cx-25,cy+40,cx-20,cy+45, 0xFFD500);
				line(buffer, cx-20,cy+45,cx-10,cy+40, 0xFFD500);
				//pintar_motor(-90, cx, cy, buffer);
				
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.9;				

			}
			
			if(key[KEY_A] && combustible_nivel > 0){
				aceleracion(90, vx, vy);
				
				line(buffer, cx+35,cy+10,cx+40,cy+25, 0xFFD500);
				line(buffer, cx+40,cy+25,cx+35,cy+30, 0xFFD500);
				line(buffer, cx+35,cy+30,cx+40,cy+45, 0xFFD500);
				line(buffer, cx+40,cy+45,cx+25,cy+40, 0xFFD500);
				line(buffer, cx+25,cy+40,cx+20,cy+45, 0xFFD500);
				line(buffer, cx+20,cy+45,cx+10,cy+40, 0xFFD500);
				
				//pintar_motor(90, cx, cy, buffer);
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.9;				

			}
			
			if(key[KEY_S] && combustible_nivel > 0){
				aceleracion(180, vx, vy);
				pintar_motor(180, cx, cy, buffer);
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.9;				

			}
			/////////////
			if(cx+25 >= 1200 || cx-25 <=0  || cy -15<= 0 || cy+35 >= 700){			
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}
							
			}
			if(choque_nave(num_nivel, cx, cy) == true){
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}

			}
			////////////
			
			textout_centre_ex(buffer, font, "COMBUSTIBLE", 550, 30, 0xFBFF00, 0x000000);
			rectfill(buffer, 450, 50, 450+combustible_nivel, 70 ,0xFF00FB);
			
			
			/////////////
			
	
			pintar_nave(cx, cy, buffer);
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			
			avanzar_nivel(cx, cy, vx, vy, num_nivel, combustible, buffer );////////////////////////////////////////
			
			rest(20);
	    }
	}
	////////////////////////////
	
	//NIVEL 2
	
	if(nivel2_seleccionado==true){		
		float nivel2_carga=0;
		BITMAP *stage2 = load_bitmap("stage2.bmp", NULL);
		BITMAP *stage2_2 = load_bitmap("stage2_2.bmp", NULL);
		BITMAP *stage2_3 = load_bitmap("stage2_3.bmp", NULL);
		while(nivel2_carga<=1160){
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			if((nivel2_carga>=0 && nivel2_carga<50)||(nivel2_carga>=150 && nivel2_carga<200)||(nivel2_carga>=300 && nivel2_carga<350) || (nivel2_carga>=450 && nivel2_carga<500) || (nivel2_carga>=600 && nivel2_carga<650) || (nivel2_carga>=750 && nivel2_carga<800) || (nivel2_carga>=900 && nivel2_carga<950) || (nivel2_carga>=1050 && nivel2_carga<1100)){
				blit(stage2, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel2_carga>=50 && nivel2_carga<100)||(nivel2_carga>=200 && nivel2_carga<250) || (nivel2_carga>=350 && nivel2_carga<400) || (nivel2_carga>=500 && nivel2_carga<550) || (nivel2_carga>=650 && nivel2_carga<700) || (nivel2_carga>=800 && nivel2_carga<850) || (nivel2_carga>=950 && nivel2_carga<1000) || (nivel2_carga>=1100 && nivel2_carga<1150)){
				blit(stage2_2, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel2_carga>=100 && nivel2_carga<150)||(nivel2_carga>=250 && nivel2_carga<300) || (nivel2_carga>=400 && nivel2_carga<450) || (nivel2_carga>=550 && nivel2_carga<600) || (nivel2_carga>=700 && nivel2_carga<750) || (nivel2_carga>=850 && nivel2_carga<900) || (nivel2_carga>=1000 && nivel2_carga<1050)){
				blit(stage2_3, buffer, 0, 0, 0, 0, 1200, 700);
			}										
			rectfill(buffer, 20, 630, 20+nivel2_carga, 680, 0xFF0000 );
			nivel2_carga=nivel2_carga+0.3;
		}
		
		int num_nivel = 2;
		float combustible_nivel=200;

		float camino_x, camino_y;
		float cx, cy;
		float vx=0, vy=0;
		
		float x1y, x2y, p1y, p2y;
		if( num_nivel ==1){
			cx= 60;
			cy= 60;	
		}
	
		if( num_nivel ==2){
			cx= 60;
			cy= 600;	
		}
		
		if( num_nivel ==3){
			cx= 60;
			cy= 60;	
		}
		
		if( num_nivel ==4){
			cx= 60;
			cy= 600;		
		}
		
		float combustible= 100, Timme = 500;  
	
	
		while( /*!key[KEY_ESC] && !Game_Over(cx, cy, buffer, num_nivel) &&*/ !aterrizar(cx, cy, vx, vy, buffer, num_nivel) ){
			bool gastar_combustible = false;
			clear_to_color(buffer,0x000000); // se limpia el buffer
			pintar_nivel(num_nivel, buffer);			
			
			pintar_nave(cx, cy, buffer); // pintar el buffer 
			mover_nave(cx,cy,vx,vy);	
				
			if(key[KEY_W] && combustible_nivel > 0){
				aceleracion(0, vx, vy);  //cuando el ang es igual a cero la aceleracion es hacia arrriba
			    
			    line(buffer, cx-15,cy+40,cx-10,cy+50, 0xFFD500);
				line(buffer, cx-10,cy+50,cx-5,cy+45, 0xFFD500);
				line(buffer, cx-5,cy+45,cx,cy+60, 0xFFD500);
				line(buffer, cx+15,cy+40,cx+10,cy+50, 0xFFD500);
				line(buffer, cx+10,cy+50,cx+5,cy+45, 0xFFD500);
				line(buffer, cx+5,cy+45,cx,cy+60, 0xFFD500);
			    
				gastar_combustible = true;
			
				combustible_nivel=combustible_nivel-0.5;				
		
			}
			
			if(key[KEY_D] && combustible_nivel > 0){
				aceleracion(-90, vx, vy);
				
				line(buffer, cx-35,cy+10,cx-40,cy+25, 0xFFD500);
				line(buffer, cx-40,cy+25,cx-35,cy+30, 0xFFD500);
				line(buffer, cx-35,cy+30,cx-40,cy+45, 0xFFD500);
				line(buffer, cx-40,cy+45,cx-25,cy+40, 0xFFD500);
				line(buffer, cx-25,cy+40,cx-20,cy+45, 0xFFD500);
				line(buffer, cx-20,cy+45,cx-10,cy+40, 0xFFD500);
				
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.5;				

			}
			
			if(key[KEY_A] && combustible_nivel > 0){
				aceleracion(90, vx, vy);
				
				line(buffer, cx+35,cy+10,cx+40,cy+25, 0xFFD500);
				line(buffer, cx+40,cy+25,cx+35,cy+30, 0xFFD500);
				line(buffer, cx+35,cy+30,cx+40,cy+45, 0xFFD500);
				line(buffer, cx+40,cy+45,cx+25,cy+40, 0xFFD500);
				line(buffer, cx+25,cy+40,cx+20,cy+45, 0xFFD500);
				line(buffer, cx+20,cy+45,cx+10,cy+40, 0xFFD500);
				
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.5;				

			}
			
			if(key[KEY_S] && combustible_nivel > 0){
				aceleracion(180, vx, vy);
				pintar_motor(180, cx, cy, buffer);
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.5;				

			}
			/////////////
			if(cx+25 >= 1200 || cx-25 <=0  || cy -15<= 0 || cy+35 >= 700){			
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}
							
			}
			if(choque_nave(num_nivel, cx, cy) == true){
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}

			}
			////////////
			textout_centre_ex(buffer, font, "COMBUSTIBLE", 550, 30, 0xFBFF00, 0x000000);
			rectfill(buffer, 450, 50, 450+combustible_nivel, 70 ,0xFF00FB);
	
			pintar_nave(cx, cy, buffer);
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			
			avanzar_nivel(cx, cy, vx, vy, num_nivel, combustible, buffer );////////////////////////////////////////
			
			rest(20);
	    }
		
		
					
	}
	
	////////////////////////////
	
	//NIVEL 3
	
	if(nivel3_seleccionado==true){
		
		float nivel3_carga=0;
		BITMAP *stage3 = load_bitmap("stage3.bmp", NULL);
		BITMAP *stage3_2 = load_bitmap("stage3_2.bmp", NULL);
		BITMAP *stage3_3 = load_bitmap("stage3_3.bmp", NULL);
		while(nivel3_carga<=1160){
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			if((nivel3_carga>=0 && nivel3_carga<50)||(nivel3_carga>=150 && nivel3_carga<200)||(nivel3_carga>=300 && nivel3_carga<350) || (nivel3_carga>=450 && nivel3_carga<500) || (nivel3_carga>=600 && nivel3_carga<650) || (nivel3_carga>=750 && nivel3_carga<800) || (nivel3_carga>=900 && nivel3_carga<950) || (nivel3_carga>=1050 && nivel3_carga<1100)){
				blit(stage3, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel3_carga>=50 && nivel3_carga<100)||(nivel3_carga>=200 && nivel3_carga<250) || (nivel3_carga>=350 && nivel3_carga<400) || (nivel3_carga>=500 && nivel3_carga<550) || (nivel3_carga>=650 && nivel3_carga<700) || (nivel3_carga>=800 && nivel3_carga<850) || (nivel3_carga>=950 && nivel3_carga<1000) || (nivel3_carga>=1100 && nivel3_carga<1150)){
				blit(stage3_2, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel3_carga>=100 && nivel3_carga<150)||(nivel3_carga>=250 && nivel3_carga<300) || (nivel3_carga>=400 && nivel3_carga<450) || (nivel3_carga>=550 && nivel3_carga<600) || (nivel3_carga>=700 && nivel3_carga<750) || (nivel3_carga>=850 && nivel3_carga<900) || (nivel3_carga>=1000 && nivel3_carga<1050)){
				blit(stage3_3, buffer, 0, 0, 0, 0, 1200, 700);
			}										
			rectfill(buffer, 20, 630, 20+nivel3_carga, 680, 0xFF0000 );
			nivel3_carga=nivel3_carga+0.3;
		}
		
		int num_nivel = 3;
		float combustible_nivel=200;

		float camino_x, camino_y;
		float cx, cy;
		float vx=0, vy=0;
		
		float x1y, x2y, p1y, p2y;
		if( num_nivel ==1){
			cx= 60;
			cy= 60;	
		}
	
		if( num_nivel ==2){
			cx= 60;
			cy= 600;	
		}
		
		if( num_nivel ==3){
			cx= 60;
			cy= 60;	
		}
		
		if( num_nivel ==4){
			cx= 60;
			cy= 600;		
		}
		
		float combustible= 100, Timme = 500;  
	
	
		while( /*!key[KEY_ESC] && !Game_Over(cx, cy, buffer, num_nivel) &&*/ !aterrizar(cx, cy, vx, vy, buffer, num_nivel) ){
			bool gastar_combustible = false;
			clear_to_color(buffer,0x000000); // se limpia el buffer
			pintar_nivel(num_nivel, buffer);			
			
			pintar_nave(cx, cy, buffer); // pintar el buffer 
			mover_nave(cx,cy,vx,vy);	
				
			if(key[KEY_W] && combustible_nivel > 0){
				aceleracion(0, vx, vy);  //cuando el ang es igual a cero la aceleracion es hacia arrriba
			    
			    line(buffer, cx-15,cy+40,cx-10,cy+50, 0xFFD500);
				line(buffer, cx-10,cy+50,cx-5,cy+45, 0xFFD500);
				line(buffer, cx-5,cy+45,cx,cy+60, 0xFFD500);
				line(buffer, cx+15,cy+40,cx+10,cy+50, 0xFFD500);
				line(buffer, cx+10,cy+50,cx+5,cy+45, 0xFFD500);
				line(buffer, cx+5,cy+45,cx,cy+60, 0xFFD500);
			    
				gastar_combustible = true;
			
				combustible_nivel=combustible_nivel-0.5;				
		
			}
			
			if(key[KEY_D] && combustible_nivel > 0){
				aceleracion(-90, vx, vy);
				
				line(buffer, cx-35,cy+10,cx-40,cy+25, 0xFFD500);
				line(buffer, cx-40,cy+25,cx-35,cy+30, 0xFFD500);
				line(buffer, cx-35,cy+30,cx-40,cy+45, 0xFFD500);
				line(buffer, cx-40,cy+45,cx-25,cy+40, 0xFFD500);
				line(buffer, cx-25,cy+40,cx-20,cy+45, 0xFFD500);
				line(buffer, cx-20,cy+45,cx-10,cy+40, 0xFFD500);
				
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.5;				

			}
			
			if(key[KEY_A] && combustible_nivel > 0){
				aceleracion(90, vx, vy);
				
				line(buffer, cx+35,cy+10,cx+40,cy+25, 0xFFD500);
				line(buffer, cx+40,cy+25,cx+35,cy+30, 0xFFD500);
				line(buffer, cx+35,cy+30,cx+40,cy+45, 0xFFD500);
				line(buffer, cx+40,cy+45,cx+25,cy+40, 0xFFD500);
				line(buffer, cx+25,cy+40,cx+20,cy+45, 0xFFD500);
				line(buffer, cx+20,cy+45,cx+10,cy+40, 0xFFD500);
				
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.5;				

			}
			
			if(key[KEY_S] && combustible_nivel > 0){
				aceleracion(180, vx, vy);
				pintar_motor(180, cx, cy, buffer);
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.5;				

			}
			/////////////
			if(cx+25 >= 1200 || cx-25 <=0  || cy -15<= 0 || cy+35 >= 700){			
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}
							
			}
			if(choque_nave(num_nivel, cx, cy) == true){
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}

			}
			////////////
			textout_centre_ex(buffer, font, "COMBUSTIBLE", 550, 30, 0xFBFF00, 0x000000);
			rectfill(buffer, 450, 50, 450+combustible_nivel, 70 ,0xFF00FB);
	
			pintar_nave(cx, cy, buffer);
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			
			avanzar_nivel(cx, cy, vx, vy, num_nivel, combustible, buffer );////////////////////////////////////////
			
			rest(20);
	    }	
			
	}
	
	
	////////////////////////////
	
	//NIVEL 4
	
	if(nivel4_seleccionado==true){		
		float nivel4_carga=0;
		BITMAP *stage4 = load_bitmap("stage4.bmp", NULL);
		BITMAP *stage4_2 = load_bitmap("stage4_2.bmp", NULL);
		BITMAP *stage4_3 = load_bitmap("stage4_3.bmp", NULL);
		while(nivel4_carga<=1160){
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			if((nivel4_carga>=0 && nivel4_carga<50)||(nivel4_carga>=150 && nivel4_carga<200)||(nivel4_carga>=300 && nivel4_carga<350) || (nivel4_carga>=450 && nivel4_carga<500) || (nivel4_carga>=600 && nivel4_carga<650) || (nivel4_carga>=750 && nivel4_carga<800) || (nivel4_carga>=900 && nivel4_carga<950) || (nivel4_carga>=1050 && nivel4_carga<1100)){
				blit(stage4, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel4_carga>=50 && nivel4_carga<100)||(nivel4_carga>=200 && nivel4_carga<250) || (nivel4_carga>=350 && nivel4_carga<400) || (nivel4_carga>=500 && nivel4_carga<550) || (nivel4_carga>=650 && nivel4_carga<700) || (nivel4_carga>=800 && nivel4_carga<850) || (nivel4_carga>=950 && nivel4_carga<1000) || (nivel4_carga>=1100 && nivel4_carga<1150)){
				blit(stage4_2, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel4_carga>=100 && nivel4_carga<150)||(nivel4_carga>=250 && nivel4_carga<300) || (nivel4_carga>=400 && nivel4_carga<450) || (nivel4_carga>=550 && nivel4_carga<600) || (nivel4_carga>=700 && nivel4_carga<750) || (nivel4_carga>=850 && nivel4_carga<900) || (nivel4_carga>=1000 && nivel4_carga<1050)){
				blit(stage4_3, buffer, 0, 0, 0, 0, 1200, 700);
			}										
			rectfill(buffer, 20, 630, 20+nivel4_carga, 680, 0xFF0000 );
			nivel4_carga=nivel4_carga+0.3;
		}
		
		int num_nivel = 4;
		float combustible_nivel=200;

		float camino_x, camino_y;
		float cx, cy;
		float vx=0, vy=0;
		
		float x1y, x2y, p1y, p2y;
		if( num_nivel ==1){
			cx= 60;
			cy= 60;	
		}
	
		if( num_nivel ==2){
			cx= 60;
			cy= 600;	
		}
		
		if( num_nivel ==3){
			cx= 60;
			cy= 60;	
		}
		
		if( num_nivel ==4){
			cx= 60;
			cy= 600;		
		}
		
		float combustible= 100, Timme = 500;  
	
	
		while( /*!key[KEY_ESC] && !Game_Over(cx, cy, buffer, num_nivel) &&*/ !aterrizar(cx, cy, vx, vy, buffer, num_nivel) ){
			bool gastar_combustible = false;
			clear_to_color(buffer,0x000000); // se limpia el buffer
			pintar_nivel(num_nivel, buffer);			
			
			pintar_nave(cx, cy, buffer); // pintar el buffer 
			mover_nave(cx,cy,vx,vy);	
				
			if(key[KEY_W] && combustible_nivel > 0){
				aceleracion(0, vx, vy);  //cuando el ang es igual a cero la aceleracion es hacia arrriba
			    
			    line(buffer, cx-15,cy+40,cx-10,cy+50, 0xFFD500);
				line(buffer, cx-10,cy+50,cx-5,cy+45, 0xFFD500);
				line(buffer, cx-5,cy+45,cx,cy+60, 0xFFD500);
				line(buffer, cx+15,cy+40,cx+10,cy+50, 0xFFD500);
				line(buffer, cx+10,cy+50,cx+5,cy+45, 0xFFD500);
				line(buffer, cx+5,cy+45,cx,cy+60, 0xFFD500);
			    
				gastar_combustible = true;
			
				combustible_nivel=combustible_nivel-0.2;				
		
			}
			
			if(key[KEY_D] && combustible_nivel > 0){
				aceleracion(-90, vx, vy);
				
				line(buffer, cx-35,cy+10,cx-40,cy+25, 0xFFD500);
				line(buffer, cx-40,cy+25,cx-35,cy+30, 0xFFD500);
				line(buffer, cx-35,cy+30,cx-40,cy+45, 0xFFD500);
				line(buffer, cx-40,cy+45,cx-25,cy+40, 0xFFD500);
				line(buffer, cx-25,cy+40,cx-20,cy+45, 0xFFD500);
				line(buffer, cx-20,cy+45,cx-10,cy+40, 0xFFD500);
				
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.2;				

			}
			
			if(key[KEY_A] && combustible_nivel > 0){
				aceleracion(90, vx, vy);
				
				line(buffer, cx+35,cy+10,cx+40,cy+25, 0xFFD500);
				line(buffer, cx+40,cy+25,cx+35,cy+30, 0xFFD500);
				line(buffer, cx+35,cy+30,cx+40,cy+45, 0xFFD500);
				line(buffer, cx+40,cy+45,cx+25,cy+40, 0xFFD500);
				line(buffer, cx+25,cy+40,cx+20,cy+45, 0xFFD500);
				line(buffer, cx+20,cy+45,cx+10,cy+40, 0xFFD500);
				
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.2;				

			}
			
			if(key[KEY_S] && combustible_nivel > 0){
				aceleracion(180, vx, vy);
				pintar_motor(180, cx, cy, buffer);
				gastar_combustible = true;

				combustible_nivel=combustible_nivel-0.2;				

			}
			/////////////
			if(cx+25 >= 1200 || cx-25 <=0  || cy -15<= 0 || cy+35 >= 700){			
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}
							
			}
			if(choque_nave(num_nivel, cx, cy) == true){
				explosion(cx, cy, buffer, num_nivel);
				if( num_nivel ==1){
					cx= 60;
					cy= 60;
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
			
				if( num_nivel ==2){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;	
				}
				
				if( num_nivel ==3){
					cx= 60;
					cy= 60;	
					vx=0;
					vy=0;
					combustible_nivel=200;
				}
				
				if( num_nivel ==4){
					cx= 60;
					cy= 600;
					vx=0;
					vy=0;
					combustible_nivel=200;		
				}
				
			}
			////////////
			textout_centre_ex(buffer, font, "COMBUSTIBLE", 550, 30, 0xFBFF00, 0x000000);
			rectfill(buffer, 450, 50, 450+combustible_nivel, 70 ,0xFF00FB);
	
			pintar_nave(cx, cy, buffer);
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			
			avanzar_nivel(cx, cy, vx, vy, num_nivel, combustible, buffer );////////////////////////////////////////
			
			rest(20);
	    }			
	}
	
	
	////////////////////////////
	
	//NIVEL 5
	
	if(nivel5_seleccionado==true){
		
		float nivel5_carga=0;
		BITMAP *stage5 = load_bitmap("stage5.bmp", NULL);
		BITMAP *stage5_2 = load_bitmap("stage5_2.bmp", NULL);
		BITMAP *stage5_3 = load_bitmap("stage5_3.bmp", NULL);
		while(nivel5_carga<=1160){
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
			if((nivel5_carga>=0 && nivel5_carga<50)||(nivel5_carga>=150 && nivel5_carga<200)||(nivel5_carga>=300 && nivel5_carga<350) || (nivel5_carga>=450 && nivel5_carga<500) || (nivel5_carga>=600 && nivel5_carga<650) || (nivel5_carga>=750 && nivel5_carga<800) || (nivel5_carga>=900 && nivel5_carga<950) || (nivel5_carga>=1050 && nivel5_carga<1100)){
				blit(stage5, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel5_carga>=50 && nivel5_carga<100)||(nivel5_carga>=200 && nivel5_carga<250) || (nivel5_carga>=350 && nivel5_carga<400) || (nivel5_carga>=500 && nivel5_carga<550) || (nivel5_carga>=650 && nivel5_carga<700) || (nivel5_carga>=800 && nivel5_carga<850) || (nivel5_carga>=950 && nivel5_carga<1000) || (nivel5_carga>=1100 && nivel5_carga<1150)){
				blit(stage5_2, buffer, 0, 0, 0, 0, 1200, 700);
			}
			if((nivel5_carga>=100 && nivel5_carga<150)||(nivel5_carga>=250 && nivel5_carga<300) || (nivel5_carga>=400 && nivel5_carga<450) || (nivel5_carga>=550 && nivel5_carga<600) || (nivel5_carga>=700 && nivel5_carga<750) || (nivel5_carga>=850 && nivel5_carga<900) || (nivel5_carga>=1000 && nivel5_carga<1050)){
				blit(stage5_3, buffer, 0, 0, 0, 0, 1200, 700);
			}										
			rectfill(buffer, 20, 630, 20+nivel5_carga, 680, 0xFF0000 );
			nivel5_carga=nivel5_carga+0.3;
		}		
	
		float cx5, cy5;
		float e1x, e1y;
		float e2x, e2y;
		float e3x, e3y;
		float e4x, e4y;
		float e5x, e5y;
		float e6x, e6y;
		float e7x, e7y;
		float e8x, e8y;
		
		float vx5=0, vy5=0;
		
		float o1x=0, o1y=0;
		float o2x=0, o2y=0;
		float o3x=0, o3y=0;
		float o4x=0, o4y=0;
		float o5x=0, o5y=0;
		float o6x=0, o6y=0;
		float o7x=0, o7y=0;
		float o8x=0, o8y=0;
		
		float m1x, m1y;
		float m2x, m2y;
		float m3x, m3y;
		float m4x, m4y;
		float m5x, m5y;
		float m6x, m6y;
		float m7x, m7y;
		float m8x, m8y;
		float m9x, m9y;
		float m10x, m10y;
		
		float n1x=0, n1y=3;
		float n2x=0, n2y=2;
		float n3x=0, n3y=3.4; 
		float n4x=0, n4y=4.2;
		float n5x=0, n5y=5;
		float n6x=0, n6y=2.5;
		float n7x=0, n7y=5.5;
		float n8x=0, n8y=3.7;
		float n9x=0, n9y=5.3;
		float n10x=0, n10y=4.6;
	
		float vida1_x=900, vida1_y=65;
		float vida2_x=970, vida2_y=65;
		float vida3_x=1040, vida3_y=65;
		
		float punto_inicio_1_x=100; 
		float punto_inicio_1_y=-780;
		float punto_final_1_x=300;
		float punto_final_1_y=-770;
		
		float punto_inicio_2_x=500; 
		float punto_inicio_2_y=-100;
		float punto_final_2_x=700;
		float punto_final_2_y=-90;
		
		float punto_inicio_3_x=900; 
		float punto_inicio_3_y=-320;
		float punto_final_3_x=1100;
		float punto_final_3_y=-310;
	
		int numero_de_vidas=4;
		
		float tiempo_restante=500;
		int num_nivel=5;
		
		bool nivel_5_completado=false;
	
		cx5 = 600; cy5 = 400;
		
		e1x = 30; e1y = -10;
		e2x = 193; e2y = -200;
		e3x = 356; e3y = -50;
		e4x = 519; e4y = -500;
		e5x = 682; e5y = -250;
		e6x = 845; e6y = -90;
		e7x = 1008; e7y = -120;
		e8x = 1171; e8y = -390;
		
		m1x=20, m1y=-150;
		m2x=149, m2y=-20;
		m3x=278, m3y=0;
		m4x=407, m4y=-80;
		m5x=536, m5y=-450;
		m6x=665, m6y=-240;
		m7x=794, m7y=-100;
		m8x=923, m8y=-500;
		m9x=1052, m9y=-360;
		m10x=1181, m10y=-210;
		
		while(nivel_5_completado==false){
			
			
			bool tiempo_corriendo=true;
			clear_to_color(buffer, 0x000000);
			
			textout_centre_ex(buffer, font, "NIVEL 5", 50, 30, 0x999999, 0x000000);
			textout_centre_ex(buffer, font, "VIDA", 970, 30, 0x999999, 0x000000);
			
			estrellas_1(e1x, e1y, buffer);
			caida_estrellas_1(e1x, e1y, o1x, o1y);
			
			if(e1y==800){
				e1y=0;
			}
			
			estrellas_2(e2x, e2y, buffer);
			caida_estrellas_2(e2x, e2y, o2x, o2y);
			
			if(e2y==800){
				e2y=0;
			}
			
			estrellas_3(e3x, e3y, buffer);
			caida_estrellas_3(e3x, e3y, o3x, o3y);
			
			if(e3y==800){
				e3y=0;
			}
			
			estrellas_4(e4x, e4y, buffer);
			caida_estrellas_4(e4x, e4y, o4x, o4y);
			
			if(e4y==800){
				e4y=0;
			}
			
			estrellas_5(e5x, e5y, buffer);
			caida_estrellas_5(e5x, e5y, o5x, o5y);
			
			if(e5y==800){
				e5y=0;
			}
			
			estrellas_6(e6x, e6y, buffer);
			caida_estrellas_6(e6x, e6y, o6x, o6y);
			
			if(e6y==800){
				e6y=0;
			}
			
			estrellas_7(e7x, e7y, buffer);
			caida_estrellas_7(e7x, e7y, o7x, o7y);
			
			if(e7y==800){
				e7y=0;
			}
			
			estrellas_8(e8x, e8y, buffer);
			caida_estrellas_8(e8x, e8y, o8x, o8y);
			
			if(e8y==800){
				e8y=0;
			}
			
			
			
			barra_1(punto_inicio_1_x, punto_inicio_1_y, punto_final_1_x, punto_final_1_y, buffer);
			caida_barra_1(punto_inicio_1_x, punto_inicio_1_y, punto_final_1_x, punto_final_1_y);
			
			if(punto_final_1_y>=800){
				punto_inicio_1_y=-2000;
				punto_final_1_y=-1990;
			}
			
			barra_2(punto_inicio_2_x, punto_inicio_2_y, punto_final_2_x, punto_final_2_y, buffer);
			caida_barra_2(punto_inicio_2_x, punto_inicio_2_y, punto_final_2_x, punto_final_2_y);
			
			if(punto_final_2_y>=800){
				punto_inicio_2_y=-1000;
				punto_final_2_y=-990;
			}
			
			barra_3(punto_inicio_3_x, punto_inicio_3_y, punto_final_3_x, punto_final_3_y, buffer);
			caida_barra_3(punto_inicio_3_x, punto_inicio_3_y, punto_final_3_x, punto_final_3_y);
			
			if(punto_final_3_y>=800){
				punto_inicio_3_y=-1500;
				punto_final_3_y=-1490;
			}
			
			
			meteoritos_1(m1x, m1y, buffer);
			caida_meteoritos_1( m1x, m1y,  n1x, n1y);
			
			if(m1y>=800){
				m1y=-150;
			}
			
			meteoritos_2(m2x, m2y, buffer);
			caida_meteoritos_2( m2x, m2y,  n2x, n2y);
			
			if(m2y>=800){
				m2y= -20;
			}
		
			
			
			meteoritos_3(m3x, m3y, buffer);
			caida_meteoritos_3( m3x, m3y,  n3x, n3y);
			
			if(m3y>=800){
				m3y=0;
			}
			
			
		
			
			meteoritos_4(m4x, m4y, buffer);
			caida_meteoritos_4( m4x, m4y,  n4x, n4y);
			
			if(m4y>=800){
				m4y=-200;
			}
			
			meteoritos_5(m5x, m5y, buffer);
			caida_meteoritos_5( m5x, m5y,  n5x, n5y);
			
			if(m5y>=800){
				m5y=-170;
			}
			
			meteoritos_6(m6x, m6y, buffer);
			caida_meteoritos_6( m6x, m6y,  n6x, n6y);
			
			if(m6y>=800){
				m6y=-250;
			}
			
			meteoritos_7(m7x, m7y, buffer);
			caida_meteoritos_7( m7x, m7y,  n7x, n7y);
			
			if(m7y>=800){
				m7y=-360;
			}
			
			meteoritos_8(m8x, m8y, buffer);
			caida_meteoritos_8( m8x, m8y,  n8x, n8y);
			
			if(m8y>=800){
				m8y=-480;
			}
			
			meteoritos_9(m9x, m9y, buffer);
			caida_meteoritos_9( m9x, m9y,  n9x, n9y);
			
			if(m9y>=800){
				m9y=-35;
			}
			
			meteoritos_10(m10x, m10y, buffer);
			caida_meteoritos_10( m10x, m10y,  n10x, n10y);
			
			if(m10y>=800){
				m10y=-42;
			}
	
			if(key[KEY_D] ){
				
				line(buffer, cx5-35,cy5+10,cx5-40,cy5+25, 0xFFD500);
				line(buffer, cx5-40,cy5+25,cx5-35,cy5+30, 0xFFD500);
				line(buffer, cx5-35,cy5+30,cx5-40,cy5+45, 0xFFD500);
				line(buffer, cx5-40,cy5+45,cx5-25,cy5+40, 0xFFD500);
				line(buffer, cx5-25,cy5+40,cx5-20,cy5+45, 0xFFD500);
				line(buffer, cx5-20,cy5+45,cx5-10,cy5+40, 0xFFD500);
				
				aceleracion5(-90, vx5, vy5);			
			}
			if(key[KEY_A] ){
				aceleracion5(90, vx5, vy5);
				
				line(buffer, cx5+35,cy5+10,cx5+40,cy5+25, 0xFFD500);
				line(buffer, cx5+40,cy5+25,cx5+35,cy5+30, 0xFFD500);
				line(buffer, cx5+35,cy5+30,cx5+40,cy5+45, 0xFFD500);
				line(buffer, cx5+40,cy5+45,cx5+25,cy5+40, 0xFFD500);
				line(buffer, cx5+25,cy5+40,cx5+20,cy5+45, 0xFFD500);
				line(buffer, cx5+20,cy5+45,cx5+10,cy5+40, 0xFFD500);
			}
			if(key[KEY_W]  ){
				aceleracion5(0, vx5, vy5);
				
				line(buffer, cx5-15,cy5+40,cx5-10,cy5+50, 0xFFD500);
				line(buffer, cx5-10,cy5+50,cx5-5,cy5+45, 0xFFD500);
				line(buffer, cx5-5,cy5+45,cx5,cy5+60, 0xFFD500);
				line(buffer, cx5+15,cy5+40,cx5+10,cy5+50, 0xFFD500);
				line(buffer, cx5+10,cy5+50,cx5+5,cy5+45, 0xFFD500);
				line(buffer, cx5+5,cy5+45,cx5,cy5+60, 0xFFD500);
			}
			
			if(tiempo_restante>0){
				tiempo(tiempo_corriendo, tiempo_restante, buffer);
			}
			
			
			if(cy5+10<=m1y+30 && cy5+10>=m1y-30 && cx5<=m1x+40 && cx5>=m1x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m2y+30 && cy5+10>=m2y-30 && cx5<=m2x+40 && cx5>=m2x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m3y+30 && cy5+10>=m3y-30 && cx5<=m3x+40 && cx5>=m3x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m4y+30 && cy5+10>=m4y-30 && cx5<=m4x+40 && cx5>=m4x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m5y+30 && cy5+10>=m5y-30 && cx5<=m5x+40 && cx5>=m5x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m6y+30 && cy5+10>=m6y-30 && cx5<=m6x+40 && cx5>=m6x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m7y+30 && cy5+10>=m7y-30 && cx5<=m7x+40 && cx5>=m7x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m8y+30 && cy5+10>=m8y-30 && cx5<=m8x+40 && cx5>=m8x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m9y+30 && cy5+10>=m9y-30 && cx5<=m9x+40 && cx5>=m9x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			if(cy5+10<=m10y+30 && cy5+10>=m10y-30 && cx5<=m10x+40 && cx5>=m10x-40){
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;
			}
			
	
			
			
			if(cy5<=punto_final_1_y+15 && cy5>=punto_inicio_1_y-35 && cx5>=punto_inicio_1_x && cx5<=punto_final_1_x){
				
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;	
			}
			
			if(cy5<=punto_final_2_y+15 && cy5>=punto_inicio_2_y-35 && cx5>=punto_inicio_2_x && cx5<=punto_final_2_x){
				
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;			
			}
			
			
			if(cy5<=punto_final_3_y+15 && cy5>=punto_inicio_3_y-35 && cx5>=punto_inicio_3_x && cx5<=punto_final_3_x){
				
				numero_de_vidas=numero_de_vidas-1;
				cx5 = 600; cy5 = 400;
				vx5 = 0; vy5 = 0;	
			}
			
			
			
			if(numero_de_vidas==4){
				vida1(vida1_x , vida1_y , buffer);
				vida2(vida2_x , vida2_y , buffer);
				vida3(vida3_x , vida3_y , buffer);
			}
			else{
				if(numero_de_vidas==3){
					vida1(vida1_x , vida1_y , buffer);
					vida2(vida2_x , vida2_y , buffer);
				}
				else{
					if(numero_de_vidas==2){
						vida1(vida1_x , vida1_y , buffer);
					}
					else{
						if(numero_de_vidas==1){
							
						}
					}
				}
			}
			if(numero_de_vidas==0 || cx5+20 >= 1200 || cx5-20<=0 || cy5-15 <= 0 || cy5+20>= 700){
				
				explosion5(cx5, cy5,buffer,num_nivel);
				vx5=0, vy5=0;
		
				o1x=0, o1y=0;
				o2x=0, o2y=0;
				o3x=0, o3y=0;
				o4x=0, o4y=0;
				o5x=0, o5y=0;
				o6x=0, o6y=0;
				o7x=0, o7y=0;
				o8x=0, o8y=0;
		
				n1x=0, n1y=3;
				n2x=0, n2y=2;
				n3x=0, n3y=3.4; 
				n4x=0, n4y=4.2;
				n5x=0, n5y=5;
				n6x=0, n6y=2.5;
				n7x=0, n7y=5.5;
				n8x=0, n8y=3.7;
				n9x=0, n9y=5.3;
				n10x=0, n10y=4.6;
	
				vida1_x=900, vida1_y=65;
				vida2_x=970, vida2_y=65;
				vida3_x=1040, vida3_y=65;
		
		
				punto_inicio_1_x=100; 
				punto_inicio_1_y=-780;
				punto_final_1_x=300;
				punto_final_1_y=-770;
		
				punto_inicio_2_x=500; 
				punto_inicio_2_y=-100;
				punto_final_2_x=700;
				punto_final_2_y=-90;
		
				punto_inicio_3_x=900; 
				punto_inicio_3_y=-320;
				punto_final_3_x=1100;
				punto_final_3_y=-310;
		
				numero_de_vidas=4;
	
	
				cx5 = 600; cy5 = 400;
		
				e1x = 30; e1y = -10;
				e2x = 193; e2y = -200;
				e3x = 356; e3y = -50;
				e4x = 519; e4y = -500;
				e5x = 682; e5y = -250;
				e6x = 845; e6y = -90;
				e7x = 1008; e7y = -120;
				e8x = 1171; e8y = -390;
	
				m1x=20, m1y=-150;
				m2x=149, m2y=-20;
				m3x=278, m3y=0;
				m4x=407, m4y=-80;
				m5x=536, m5y=-450;
				m6x=665, m6y=-240;
				m7x=794, m7y=-100;
				m8x=923, m8y=-500;
				m9x=1052, m9y=-360;
				m10x=1181, m10y=-210;
		
				tiempo_restante=500;
				num_nivel=2;		
			}
			textout_centre_ex(buffer, font, "TIEMPO", 480, 30, 0x999999, 0x000000);
	
			pintar_nave5(cx5,cy5,buffer);
			blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
	
			caida_nave5(cx5,cy5,vx5,vy5);
			
			if(tiempo_restante<=0){
				nivel_5_completado=true;
			}
			rest(10);
		}		
	}
	
	
	
	////////////////////////////////////
	
	BITMAP *ganaste = load_bitmap("ganaste.bmp", NULL); 
	
	while(!key[KEY_ESC]){
		blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
		blit(ganaste, buffer, 0, 0, 0, 0, 1200, 700);
	}	

	return 0;	
}	

 END_OF_MAIN();
 
 
 //NIVELES 1, 2, 3, 4
 
bool choque_nave(int num_nivel, float cx, float cy){
 	//izquierda
 	float r1x = cx-25, r1y= cy;
 	float r2x = cx, r2y= cy+25; 
 	
 	//derecha
 	float p1x = cx, p1y= cy;
 	float p2x = cx+25, p2y= cy+25;
 	
 	//cuerpo
 	float q1x = cx-20, q1y= cy-20;
 	float q2x = cx+20, q2y= cy+25;
 	
	
 	
 	if(num_nivel==4){
 		if(choque_triangulo( 120 , 280, 200, 680, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 120 , 280, 200, 680, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 120 , 280, 200, 680, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
		
		
		else if(choque_triangulo( 200, 680, 320, 440, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 200, 680, 320, 440, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 200, 680, 320, 440, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
			
		
		else if(choque_triangulo( 320 , 440, 440, 680, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 320 , 440, 440, 680, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 320 , 440, 440, 680, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
			
		
		else if(choque_triangulo( 440, 680, 560, 440, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 440, 680, 560, 440, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 440, 680, 560, 440, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
				
		
		else if(choque_triangulo( 560 , 440, 720, 680, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 560 , 440, 720, 680, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 560 , 440, 720, 680, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
				
		
		else if(choque_triangulo( 720 , 200, 920, 680, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 720 , 200, 920, 680, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 720 , 200, 920, 680, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
			
		
		else if(choque_triangulo( 920, 700, 950, 400, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 920, 700, 950, 400, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 920, 700, 950, 400, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
				
		else if(choque_triangulo( 950 , 400, 1080, 700, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 950 , 400, 1080, 700, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 950 , 400, 1080, 700, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
			 		
		else if(choque_triangulo( 1120 , 700, 1200, 520, r1x, r1y, r2x, r2y, "abajo") == true || choque_triangulo( 1120 , 700, 1200, 520, p1x, p1y, p2x, p2y, "abajo") == true || choque_triangulo( 1120 , 700, 1200, 520, q1x, q1y, q2x, q2y, "abajo") == true)
 			return true;
			 		
		
		
		
		else if(choque_triangulo( 120 , 160, 160, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 120 , 160, 160, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 120 , 160, 160, 0, q1x, q1y, q2x, q2y, "arriba") == true)
 			return true;
					
		else if(choque_triangulo( 240 , 400, 320, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 240 , 400, 320, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 240 , 400, 320, 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		else if(choque_triangulo( 0 , 400, 80 , 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 0 , 400, 80 , 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 0 , 400, 80 , 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
			
		else if(choque_triangulo( 80, 0, 120, 160, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 80, 0, 120, 160, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 80, 0, 120, 160, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		else if(choque_triangulo( 160, 0, 240 , 400, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 160, 0, 240 , 400, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 160, 0, 240 , 400, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		if(choque_triangulo( 440 , 400, 600, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 440 , 400, 600, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 440 , 400, 600, 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		if(choque_triangulo( 320, 0,  440, 400, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 320, 0,  440, 400, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 320, 0,  440, 400, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
	
		if(choque_triangulo( 440, 0, 600 , 320, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 440, 0, 600 , 320, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 440, 0, 600 , 320, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		else if(choque_triangulo( 640, 80, 680 , 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 640, 80, 680 , 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 640, 80, 680 , 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		if(choque_triangulo( 640, 0, 640 , 80, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 640, 0, 640 , 80, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 640, 0, 640 , 80, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		if(choque_triangulo( 680, 0, 720 , 80, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 680, 0, 720 , 80, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 680, 0, 720 , 80, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
	
		if(choque_triangulo( 720 , 80, 760, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 720 , 80, 760, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 720 , 80, 760, 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}
	
		if(choque_triangulo( 760, 0, 840 , 200, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 760, 0, 840 , 200, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 760, 0, 840 , 200, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
	
		if(choque_triangulo( 840, 200, 920 , 0,  r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 840, 200, 920 , 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 840, 200, 920 , 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}
		
	
	
		if(choque_triangulo( 1000, 0, 1040 , 80, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1000, 0, 1040 , 80, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1000, 0, 1040 , 80, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		if(choque_triangulo( 1040, 0, 1080 , 80, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1040, 0, 1080 , 80, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1040, 0, 1080 , 80, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
	
		if(choque_triangulo( 1080, 0, 1120 , 80, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1080, 0, 1120 , 80, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1080, 0, 1120 , 80, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		else if(choque_triangulo( 1120, 0, 1160 , 80, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1120, 0, 1160 , 80, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1120, 0, 1160 , 80, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		if(choque_triangulo( 1160, 0, 1200 , 80, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1160, 0, 1200 , 80, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1160, 0, 1200 , 80, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
		
		if(choque_triangulo( 1040 , 80, 1080, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1040 , 80, 1080, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1040 , 80, 1080, 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
	
		if(choque_triangulo( 1080 , 80, 1120, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1080 , 80, 1120, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1080 , 80, 1120, 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}
	
		if(choque_triangulo( 1120 , 80, 1160, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1120 , 80, 1160, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1120 , 80, 1160, 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}		
	
		if(choque_triangulo( 1160 , 80, 1200, 0, r1x, r1y, r2x, r2y, "arriba") == true || choque_triangulo( 1160 , 80, 1200, 0, p1x, p1y, p2x, p2y, "arriba") == true || choque_triangulo( 1160 , 80, 1200, 0, q1x, q1y, q2x, q2y, "arriba") == true){
 			return true;
		}
	

        	}
        	
        	
        if(num_nivel==2){
        	
			if(choque_triangulo( 140, 700, 400, 300,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo(140, 700, 400, 300, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo(140, 700, 400, 300, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  400, 300, 400, 700,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 400, 300, 400, 700, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 400, 300, 400, 700, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  600,700 ,860 , 300,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 600,700 ,860 , 300, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 600,700 ,860 , 300, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  860 , 300,860 ,700,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 860 , 300,860 ,700, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 860 , 300,860 ,700, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  860 ,700 ,860 ,300,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 860 ,700 ,860 ,300, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 860 ,700 ,860 ,300, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  860 ,300 ,1200 ,700,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 860 ,300 ,1200 ,700, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 860 ,300 ,1200 ,700, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  900 ,600 ,1200 ,700,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 900 ,600 ,1200 ,700, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 900 ,600 ,1200 ,700, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  1020 ,700 ,1200 ,290,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 1020 ,700 ,1200 ,290, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 1020 ,700 ,1200 ,290, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo(  500 ,0 ,500 ,600,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo( 500 ,0 ,500 ,600, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo( 500 ,0 ,500 ,600, q1x, q1y, q2x, q2y,"arriba")==true)return true;	
			else if(choque_triangulo(  500 ,600 ,890 , 0,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo( 500 ,600 ,890 , 0, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo( 500 ,600 ,890 , 0, q1x, q1y, q2x, q2y,"arriba")==true)return true;	
			else if(choque_triangulo(  0 ,0 , 0, 600,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo( 0 ,0 , 0, 600, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo( 0 ,0 , 0, 600, q1x, q1y, q2x, q2y,"arriba")==true)return true;	
			else if(choque_triangulo(   0, 600,400 ,0,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo(  0, 600,400 ,0, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo(  0, 600,400 ,0, q1x, q1y, q2x, q2y,"arriba")==true)return true;	
		
		}	
		
		else if(num_nivel==3){
			if(choque_triangulo(  0, 900, 533, 102,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo( 0, 900, 533, 102, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo( 0, 900, 533, 102, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo( 533, 102, 533, 700,r1x, r1y, r2x, r2y, "abajo")==true || choque_triangulo(533, 102, 533, 700, p1x, p1y, p2x, p2y,"abajo")==true|| choque_triangulo(533, 102, 533, 700, q1x, q1y, q2x, q2y,"abajo")==true)return true;	
			else if(choque_triangulo( 100,0 , 100, 500,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo(100,0 , 100, 500, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo(100,0 , 100, 500, q1x, q1y, q2x, q2y,"arriba")==true)return true;	
			else if(choque_triangulo( 100, 500, 433, 0,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo(100, 500, 433, 0, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo(100, 500, 433, 0, q1x, q1y, q2x, q2y,"arriba")==true)return true;	
			else if(choque_triangulo( 700 ,0 ,700,600,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo(700 ,0 ,700,600, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo(700 ,0 ,700,600, q1x, q1y, q2x, q2y,"arriba")==true)return true;	
			else if(choque_triangulo( 700,600,1010,0,r1x, r1y, r2x, r2y, "arriba")==true || choque_triangulo(700,600,1010,0, p1x, p1y, p2x, p2y,"arriba")==true|| choque_triangulo(700,600,1010,0, q1x, q1y, q2x, q2y,"arriba")==true)return true;	

	}
		
	
        	
 	return false;
 	
 	
 	
 }
 
 
 
 
 
 
 bool choque_triangulo(float x1, float y1, float x2, float y2, float p1x, float p1y, float p2x, float p2y, string tipo_triangulo){
 	float m= (y2-y1)/(x2-x1);
 	
 	float b= y1-m*x1;
 	
 	
 	if(tipo_triangulo == "abajo"){
	
 	if(m>0){
 		if(x1 <= p1x && p1x <= x2){
 			if(p2y >= m*p1x + b) return true;
 			
		 }
		 else{
		 	if(p1x <= x1 && x1 <= p2x)
		 		if(y1 <= p2y) return true;
		 }
		 
	 }
 	
 	else if(m<0){
 		if(x1 <= p2x && p2x <= x2){
 			if(p2y >= m*p2x + b) return true;
 			
		 }
		 else{
		 	if(p1x <= x2 && x2 <= p2x)
		 		if(y2 <= p2y) return true;
		 }
		
	 }
	 
	}
	
	if(tipo_triangulo == "arriba"){
		
	if(m>0){
 		if(x1 <= p2x && p2x <= x2){
 			if(p1y <= m*p2x + b) return true;
 			
		 }
		 else{
		 	if(p1x <= x2 && x2 <= p2x)
		 	if(p1y <= y2) return true;
		 }
		 
		 return false;
		 
	 }
 	
 	else{
 		if(x1 <= p1x && p1x <= x2){
 			if(p1y <= m*p1x + b) return true;
 			
		 }
		 else{
		 	if(p1x <= x1 && x1 <= p2x)
		 		if(p1y <= y1) return true;
		 }
		 return false;
		
	 }	
		
	}
	
 	return false;
 	
 }
 
 
 
void avanzar_nivel(float &cx, float &cy, float &vx, float &vy, int &num_nivel, float &combustible, BITMAP *buffer){
 
 	if(num_nivel==1){
	
 			
 			if( aterrizar(cx, cy, vx, vy, buffer, num_nivel) == true){

 		vy= -0.2; vx= 0;
 		if(num_nivel !=4) num_nivel++;
	 }	 
 		
 		 	textout_centre_ex( screen, font, " NIVEL 1", 50, 50, 0xF1E90E, 0x000000);
 		
	 }
 
 
 	if(num_nivel==2){
	 
 	if( aterrizar(cx, cy, vx, vy, buffer, num_nivel) == true){
 
 		vy= -0.2; vx= 0;
 		if(num_nivel !=4) num_nivel++;
		 
 	}	
 		 
 		 textout_centre_ex( screen, font, " NIVEL 2", 50, 50, 0xF1E90E, 0x000000);
	 }
	 
	 
 	if(num_nivel==4){
	 
 	if( aterrizar(cx, cy, vx, vy, buffer, num_nivel) == true){

 		vy= -0.2; vx= 0;
 		if(num_nivel !=4) num_nivel++;
		 
 	}	
 		   textout_centre_ex( screen, font, " NIVEL 4", 50, 50, 0xF1E90E, 0x000000);
	 } 	
	 
	 	if(num_nivel==3){
	 
 	if( aterrizar(cx, cy, vx, vy, buffer, num_nivel) == true){

 		vy= -0.2; vx= 0;
 		if(num_nivel !=4) num_nivel++;
		 
 	}	
 		   textout_centre_ex( screen, font, " NIVEL 3", 50, 50, 0xF1E90E, 0x000000);
	 } 	
	 
	 
 		
		 combustible = 100;
		
}
 	
 
bool aterrizar(float cx, float cy, float vx, float vy, BITMAP * buffer, int num_nivel){
	
	

if(cx+25<=1153 && cx-25>= 950 && cy-15<=450 && cy+35>=340) {
		if(vy<=1.5) {
		return true;
	} 
	//rectfill( buffer, 1, 0 , 125, 8, 0x999999)
	else explosion(cx, cy, buffer, num_nivel);
}
	
	return false;
		
		
		
}

void explosion(float cx, float cy, BITMAP * buffer, int num_nivel){
	float x[12]={cx-10, cx+10, cx, cx, cx+15, cx-15, cx+5, cx-10, cx+10, cx-5, cx-10, cx+10};
	float y[12]={cy, cy, cy-15, cy+15, cy-15, cy+15, cy+5, cy-10, cy-10, cy+10, cy, cy};
	
	float dx[6]={7, 7, 0, -7, -7, 0};
	float dy[6]={0, -7, -7, -7, 0, 7};

	clear(screen);
	
	do{
		clear(buffer);
		pintar_nivel(num_nivel, buffer);
		int j=0;
		for(int i=0; i<=10; i+=2){
			line(buffer, x[i], y[i], x[i+1], y[i+1], 0xFFFFFF);
			rotar(x[i+1], y[i+1], x[i], y[i], 15);
			
			x[i]+= dx[j];
			y[i]+= dy[j];
			x[i+1]+= dx[j];
			y[i+1]+= dy[j];
			j++;
			
		}
		
	
		textout_centre_ex(buffer, font, " GAME OVER", 600, 350, 0XE81212, 0X000000);
		textout_centre_ex(buffer, font, "PRESIONE (ENTER) PARA EMPEZAR DE NUEVO", 600, 370, 0XFBFF00, 0X000000);
		blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
		rest(20);
		
	}while(!key[KEY_ENTER] );
}
 
 
void pintar_nivel( int num_nivel, BITMAP *buffer ){
	
	if(num_nivel ==1){

		rectfill(buffer,970, 347, 1153, 360, 0x31adfb);
		rectfill(buffer, 1000, 390, 1123, 410, 0x31adfb);
		line(buffer,1041, 410, 1041,450, 0x31adfb);
		line(buffer, 1082, 410, 1082, 450, 0x31adfb);
		
		line(buffer, 950, 347,1000 , 390, 0xf93c1c);
		line(buffer,1173 , 347 , 1123, 390, 0xf93c1c);
		
		line(buffer,980 ,400 , 1000,400 , 0xf93c1c);
		line(buffer,1123 ,400 , 1143,400 , 0xf93c1c);
		

		triangle(buffer, 1000,360 , 1041 ,360 , 1041 ,390 , 0x999999);////triangulo interior
		triangle(buffer, 1082,360 , 1082 ,390 , 1123 ,360 , 0x999999);//triangulo interior


	}
	
	
	
	if(num_nivel == 2 ){
		
		rectfill(buffer,970, 347, 1153, 360, 0x31adfb);
		rectfill(buffer, 1000, 390, 1123, 410, 0x31adfb);
		line(buffer,1041, 410, 1041,450, 0x31adfb);
		line(buffer, 1082, 410, 1082, 450, 0x31adfb);
		
		line(buffer, 950, 347,1000 , 390, 0xf93c1c);
		line(buffer,1173 , 347 , 1123, 390, 0xf93c1c);
		
		line(buffer,980 ,400 , 1000,400 , 0xf93c1c);
		line(buffer,1123 ,400 , 1143,400 , 0xf93c1c);
		

		triangle(buffer, 1000,360 , 1041 ,360 , 1041 ,390 , 0x999999);////triangulo interior
		triangle(buffer, 1082,360 , 1082 ,390 , 1123 ,360 , 0x999999);//triangulo interior

		
		line(buffer,1000 ,410 ,1041 ,450, 0x999999);
		line(buffer, 1041,450 , 1082,410 , 0x999999);
		line(buffer, 1123, 410, 1082,450 , 0x999999);
		line(buffer,1041 ,410 ,1082 ,450 , 0x999999);
		
		
		triangle(buffer, 140, 700, 400, 300, 400, 700,0x999999);//abajo
		triangle(buffer, 600,700 ,860 , 300,860 ,700 , 0x999999);//abajo
		triangle(buffer,860 ,700 ,860 ,300 ,1200 ,700 , 0x999999);//abajo
		
		triangle(buffer,500 ,0 ,500 ,600 ,890 , 0 ,0x999999); //arriba
		triangle(buffer,0 ,0 , 0, 600,400 ,0 , 0x999999);//arribe
		
			
		
		
		
			
	}
	
	if(num_nivel ==3){
		

		
		triangle(buffer, 0, 900, 533, 102, 533, 700, 0X999999);	//abajo
		triangle(buffer, 100,0 , 100, 500, 433, 0, 0X999999); //arriba

		triangle(buffer, 700 ,0 ,700,600,1010,0 ,0X999999); //Arriba final

		
		rectfill(buffer,970, 347, 1153, 360, 0x31adfb);
		rectfill(buffer, 1000, 390, 1123, 410, 0x31adfb);
		line(buffer,1041, 410, 1041,450, 0x31adfb);
		line(buffer, 1082, 410, 1082, 450, 0x31adfb);
		
		line(buffer, 950, 347,1000 , 390, 0xf93c1c);
		line(buffer,1173 , 347 , 1123, 390, 0xf93c1c);
		
		line(buffer,980 ,400 , 1000,400 , 0xf93c1c);
		line(buffer,1123 ,400 , 1143,400 , 0xf93c1c);
		

		triangle(buffer, 1000,360 , 1041 ,360 , 1041 ,390 , 0x999999);////triangulo interior
		triangle(buffer, 1082,360 , 1082 ,390 , 1123 ,360 , 0x999999);//triangulo interior

		
		
		
	}
	
	if(num_nivel == 4 ){
				
		triangle(buffer, 120, 700, 120 , 280, 200, 700, 0x999999);	
		triangle(buffer, 200, 700, 320 , 680, 320, 440, 0x999999);
		triangle(buffer, 320, 700, 320 , 440, 440, 700, 0x999999);
		triangle(buffer, 440, 700, 560 , 680, 560, 440, 0x999999);	
		triangle(buffer, 560, 700, 560 , 440, 720, 700, 0x999999);			
		triangle(buffer, 720, 700, 720 , 200, 920, 700, 0x999999);		
		triangle(buffer, 920, 700, 950 , 400, 950, 700, 0x999999);
		triangle(buffer, 950, 700, 950 , 400, 1080, 700, 0x999999);
		triangle(buffer, 1120, 700, 1200 , 520, 1200, 700, 0x999999);//		
		
		triangle(buffer, 120, 700, 120 , 280, 200, 700, 0x999999);	
		triangle(buffer, 200, 700, 320 , 700, 320, 440, 0x999999);
		triangle(buffer, 320, 700, 320 , 440, 440, 700, 0x999999);
		triangle(buffer, 440, 700, 560 , 700, 560, 440, 0x999999);	
		triangle(buffer, 560, 700, 560 , 440, 720, 700, 0x999999);			
		triangle(buffer, 720, 700, 720 , 200, 920, 700, 0x999999);	

		
		triangle(buffer, 0, 0, 0 , 400, 80 , 0, 0x999999);	
		triangle(buffer, 80, 0, 120, 160, 120 , 0, 0x999999);			
		triangle(buffer, 120, 0, 120 , 160, 160, 0, 0x999999);			
		triangle(buffer, 240, 0, 240 , 400, 320, 0, 0x999999);
		triangle(buffer, 160, 0, 240 , 400, 240, 0, 0x999999);	
		triangle(buffer, 440, 0, 440 , 400, 600, 0, 0x999999);
		triangle(buffer, 320, 0,  440, 400, 440 , 0, 0x999999);
		triangle(buffer, 440, 0, 600 , 320, 600, 0, 0x999999);		
		triangle(buffer, 600, 0, 640 , 80, 640, 0, 0x999999);	
		triangle(buffer, 640, 0, 640 , 80, 680, 0, 0x999999);
		triangle(buffer, 680, 0, 720 , 80, 720, 0, 0x999999);
		triangle(buffer, 720, 0, 720 , 80, 760, 0, 0x999999);	
		triangle(buffer, 760, 0, 840 , 200, 840, 0, 0x999999);		
		triangle(buffer, 840, 0, 840 , 200, 920, 0, 0x999999);	
		triangle(buffer, 1000, 0, 1040 , 80, 1040, 0, 0x999999);
		triangle(buffer, 1040, 0, 1080 , 80, 1080, 0, 0x999999);
		triangle(buffer, 1080, 0, 1120 , 80, 1120, 0, 0x999999);
		triangle(buffer, 1120, 0, 1160 , 80, 1160, 0, 0x999999);	
		triangle(buffer, 1160, 0, 1200 , 80, 1200, 0, 0x999999);
		triangle(buffer, 1040, 0, 1040 , 80, 1080, 0, 0x999999);
		triangle(buffer, 1080, 0, 1080 , 80, 1120, 0, 0x999999);
		triangle(buffer, 1120, 0, 1120 , 80, 1160, 0, 0x999999);	
		triangle(buffer, 1160, 0, 1160 , 80, 1200, 0, 0x999999);
		
		rectfill(buffer,970, 347, 1153, 360, 0x31adfb);
		rectfill(buffer, 1000, 390, 1123, 410, 0x31adfb);
		line(buffer,1041, 410, 1041,450, 0x31adfb);
		line(buffer, 1082, 410, 1082, 450, 0x31adfb);
		
		line(buffer, 950, 347,1000 , 390, 0xf93c1c);
		line(buffer,1173 , 347 , 1123, 390, 0xf93c1c);
		
		line(buffer,980 ,400 , 1000,400 , 0xf93c1c);
		line(buffer,1123 ,400 , 1143,400 , 0xf93c1c);
		

		triangle(buffer, 1000,360 , 1041 ,360 , 1041 ,390 , 0x999999);////triangulo interior
		triangle(buffer, 1082,360 , 1082 ,390 , 1123 ,360 , 0x999999);//triangulo interior



	}	
	
	
	
} 



void pintar_motor(float da, float cx, float cy, BITMAP *buffer){

	float c1, c2;
	c1= cx;
	c2= cy;
	if(da!=0) c2+=10;
	float fuego[14]= {c1-5, c2+5,  c1-10, c2+20,  c1-5, c2+20,  c1, c2+35,  c1+5, c2+20,  c1+10, c2+20, c1+5, c2+5};
	for( int i = 0; i <=12; i+=2){
		rotar(fuego[i], fuego[i+1], cx, cy, da);
	}
	
	for( int i = 0; i <=10; i+=2){
		line(buffer, fuego[i], fuego[i+1], fuego[i+2], fuego[i+3], 0x999999 );
	
	}
	
	
} 


void medidor_combustible(bool gastar_combustible, float &combustible, BITMAP *buffer){
	//funcion de allegro para imprimir textos
	textout_centre_ex(buffer, font, "Combustible", 100, 30, 0x999999, 0x000000 );
	rectfill(buffer, 50, 54, 50+combustible, 50, 0x999999 );	
	
	if(gastar_combustible == true ) combustible -=0.002;
	

}
 
 void aceleracion(float da, float &vx, float &vy){
 	float ax = 0, ay = -0.3;
 	rotar(ax, ay, 0, 0, da);  // si da = cero  el vector aceleracion se queda intacto el vector
 	vx = vx + ax;
 	vy = vy + ay;
 	
 }
 
 
 void pintar_nave(float cx, float cy, BITMAP *buffer){

 	line(buffer, cx-5,cy+5,cx+5,cy+5, 0xDCFF00);
	line(buffer, cx+5,cy+5,cx+15,cy, 0xDCFF00);
	line(buffer, cx-5,cy+5,cx-15,cy, 0xDCFF00);
	line(buffer, cx-15,cy,cx-10,cy-10, 0x00CDFF);
	line(buffer, cx-10,cy-10,cx-5,cy-15, 0x00CDFF);
	line(buffer, cx-5,cy-15,cx+5,cy-15, 0x00CDFF);
	line(buffer, cx+5,cy-15,cx+10,cy-10, 0x00CDFF);
	line(buffer, cx+10,cy-10,cx+15,cy, 0x00CDFF);
	line(buffer, cx-15,cy,cx-20,cy+5, 0xDCFF00);
	line(buffer, cx+15,cy,cx+20,cy+5, 0xDCFF00);
	line(buffer, cx-20,cy+5,cx-25,cy+15, 0xDCFF00);
	line(buffer, cx-25,cy+15,cx-25,cy+25, 0xDCFF00);
	line(buffer, cx-25,cy+25,cx-20,cy+30, 0xDCFF00);
	line(buffer, cx-20,cy+30,cx-15,cy+30, 0xDCFF00);
	line(buffer, cx-15,cy+30,cx-10,cy+25, 0xDCFF00);
	line(buffer, cx-10,cy+25,cx-5,cy+35, 0xDCFF00);
	line(buffer, cx-5,cy+35,cx+5,cy+35, 0xDCFF00);
	line(buffer, cx+5,cy+35,cx+10,cy+25, 0xDCFF00);
	line(buffer, cx+10,cy+25,cx+15,cy+30, 0xDCFF00);
	line(buffer, cx+15,cy+30,cx+20,cy+30, 0xDCFF00);
	line(buffer, cx+20,cy+30,cx+25,cy+25, 0xDCFF00);
	line(buffer, cx+25,cy+25,cx+25,cy+15, 0xDCFF00);
	line(buffer, cx+25,cy+15,cx+20,cy+5, 0xDCFF00);
	line(buffer, cx-20,cy+5,cx-5,cy+15, 0xDCFF00);
	line(buffer, cx-5,cy+15,cx+5,cy+15, 0xDCFF00);
	line(buffer, cx+5,cy+15,cx+20,cy+5, 0xDCFF00);
	
	line(buffer, cx,cy-10,cx-5,cy-10, 0x00CDFF);
	line(buffer, cx-5,cy-10,cx-10,cy, 0x00CDFF);
	
	
	line(buffer, cx-20,cy+5,cx-15,cy+20, 0xFF0000);
	line(buffer, cx-15,cy+20,cx,cy+25, 0xFF0000);
	line(buffer, cx+20,cy+5,cx+15,cy+20, 0xFF0000);
	line(buffer, cx+15,cy+20,cx,cy+25, 0xFF0000);
 	
 	
 	
 	
	 	
 }
  
 void mover_nave(float &cx, float &cy, float &vx, float &vy){
 	float ax, ay;
 	ax = 0;
 	ay = 0.1;
 
 	vx= vx + ax;
 	vy= vy + ay;
 	
 	cx= cx + vx;
 	cy= cy + vy;
 	
 	
 }
 
// formula     //parametros		// constantes con sus pivotes cx y cy   // diferencia del angulo
 void rotar();void rotar(float &x, float&y, float cx, float cy, float da){
	
	float dx = x - cx;
	float dy = y - cy;
	float r = sqrt(dx*dx + dy*dy);
	float a = atan2(dy, dx);  // estan en radianes
	
// pasamos da de grados a radianes
	float da_rad = da/180 * M_PI;
	a -= da_rad; // en este punto a ya vale la suma de los angulos
	
	x = cx + r*cos(a);
	y = cy + r*sin(a);
		
}
 
 
 
 
 
 
 
 //NIVEL 5
 
 void explosion5(float cx5, float cy5, BITMAP *buffer, int num_nivel){
	float x[12]={cx5-10, cx5+10, cx5, cx5, cx5+15, cx5-15, cx5+5, cx5-10, cx5+10, cx5-5, cx5-10, cx5+10};
	float y[12]={cy5, cy5, cy5-15, cy5+15, cy5-15, cy5+15, cy5+5, cy5-10, cy5-10, cy5+10, cy5, cy5};
	
	float dx[6]={7, 7, 0, -7, -7, 0};
	float dy[6]={0, -7, -7, -7, 0, 7};
	
	clear(screen);
	
	do{
		clear(buffer);
		int j=0;
		for(int i=0; i<=10; i+=2){
			line(buffer, x[i], y[i], x[i+1], y[i+1], 0xFFFFFF);
			rotar5(x[i+1], y[i+1], x[i], y[i], 15);
			
			x[i]+= dx[j];
			y[i]+= dy[j];
			x[i+1]+= dx[j];
			y[i+1]+= dy[j];
			j++;
			
		}
		textout_centre_ex(buffer, font, "GAME OVER", 590, 340, 0xFF0000, 0x000000);
		textout_centre_ex(buffer, font, "PRESIONE (ENTER) PARA INTENTARLO DE NUEVO", 600, 350, 0XFBFF00, 0X000000);
		
		blit(buffer, screen, 0, 0, 0, 0, 1200, 700);
		rest(20);
	}while(!key[KEY_ESC] && !key[KEY_ENTER]);
}

void pintar_nave5(float cx5 , float cy5 , BITMAP *buffer){
	
	line(buffer, cx5-5,cy5+5,cx5+5,cy5+5, 0xDCFF00);
	line(buffer, cx5+5,cy5+5,cx5+15,cy5, 0xDCFF00);
	line(buffer, cx5-5,cy5+5,cx5-15,cy5, 0xDCFF00);
	line(buffer, cx5-15,cy5,cx5-10,cy5-10, 0x00CDFF);
	line(buffer, cx5-10,cy5-10,cx5-5,cy5-15, 0x00CDFF);
	line(buffer, cx5-5,cy5-15,cx5+5,cy5-15, 0x00CDFF);
	line(buffer, cx5+5,cy5-15,cx5+10,cy5-10, 0x00CDFF);
	line(buffer, cx5+10,cy5-10,cx5+15,cy5, 0x00CDFF);
	line(buffer, cx5-15,cy5,cx5-20,cy5+5, 0xDCFF00);
	line(buffer, cx5+15,cy5,cx5+20,cy5+5, 0xDCFF00);
	line(buffer, cx5-20,cy5+5,cx5-25,cy5+15, 0xDCFF00);
	line(buffer, cx5-25,cy5+15,cx5-25,cy5+25, 0xDCFF00);
	line(buffer, cx5-25,cy5+25,cx5-20,cy5+30, 0xDCFF00);
	line(buffer, cx5-20,cy5+30,cx5-15,cy5+30, 0xDCFF00);
	line(buffer, cx5-15,cy5+30,cx5-10,cy5+25, 0xDCFF00);
	line(buffer, cx5-10,cy5+25,cx5-5,cy5+35, 0xDCFF00);
	line(buffer, cx5-5,cy5+35,cx5+5,cy5+35, 0xDCFF00);
	line(buffer, cx5+5,cy5+35,cx5+10,cy5+25, 0xDCFF00);
	line(buffer, cx5+10,cy5+25,cx5+15,cy5+30, 0xDCFF00);
	line(buffer, cx5+15,cy5+30,cx5+20,cy5+30, 0xDCFF00);
	line(buffer, cx5+20,cy5+30,cx5+25,cy5+25, 0xDCFF00);
	line(buffer, cx5+25,cy5+25,cx5+25,cy5+15, 0xDCFF00);
	line(buffer, cx5+25,cy5+15,cx5+20,cy5+5, 0xDCFF00);
	line(buffer, cx5-20,cy5+5,cx5-5,cy5+15, 0xDCFF00);
	line(buffer, cx5-5,cy5+15,cx5+5,cy5+15, 0xDCFF00);
	line(buffer, cx5+5,cy5+15,cx5+20,cy5+5, 0xDCFF00);
	
	line(buffer, cx5,cy5-10,cx5-5,cy5-10, 0x00CDFF);
	line(buffer, cx5-5,cy5-10,cx5-10,cy5, 0x00CDFF);
	
	
	line(buffer, cx5-20,cy5+5,cx5-15,cy5+20, 0xFF0000);
	line(buffer, cx5-15,cy5+20,cx5,cy5+25, 0xFF0000);
	line(buffer, cx5+20,cy5+5,cx5+15,cy5+20, 0xFF0000);
	line(buffer, cx5+15,cy5+20,cx5,cy5+25, 0xFF0000);

}
void estrellas_1(float e1x, float e1y, BITMAP *buffer){ 
	line(buffer, e1x ,e1y-10,e1x-2.5,e1y-2.5, 0xFBFF00);
	line(buffer, e1x-2.5,e1y-2.5,e1x-10,e1y, 0xFBFF00);
	line(buffer, e1x-10,e1y,e1x-2.5,e1y+2.5, 0xFBFF00);
	line(buffer, e1x-2.5,e1y+2.5,e1x,e1y+10, 0xFBFF00);
	line(buffer, e1x,e1y+10,e1x+2.5,e1y+2.5, 0xFBFF00);
	line(buffer, e1x+2.5,e1y+2.5,e1x+10,e1y, 0xFBFF00);
	line(buffer, e1x+10,e1y,e1x+2.5,e1y-2.5, 0xFBFF00);
	line(buffer, e1x+2.5,e1y-2.5,e1x ,e1y-10, 0xFBFF00);
}
void caida_estrellas_1(float &e1x, float &e1y, float &o1x, float &o1y){
	
	o1x = 0;
	o1y = 10;
	
	e1x += o1x;
	e1y += o1y;
}
void estrellas_2(float e2x, float e2y, BITMAP *buffer){
	line(buffer, e2x ,e2y-10,e2x-2.5,e2y-2.5, 0xFBFF00);
	line(buffer, e2x-2.5,e2y-2.5,e2x-10,e2y, 0xFBFF00);
	line(buffer, e2x-10,e2y,e2x-2.5,e2y+2.5, 0xFBFF00);
	line(buffer, e2x-2.5,e2y+2.5,e2x,e2y+10, 0xFBFF00);
	line(buffer, e2x,e2y+10,e2x+2.5,e2y+2.5, 0xFBFF00);
	line(buffer, e2x+2.5,e2y+2.5,e2x+10,e2y, 0xFBFF00);
	line(buffer, e2x+10,e2y,e2x+2.5,e2y-2.5, 0xFBFF00);
	line(buffer, e2x+2.5,e2y-2.5,e2x ,e2y-10, 0xFBFF00);
}
void caida_estrellas_2(float &e2x, float &e2y, float &o2x, float &o2y){
	
	o2x = 0;
	o2y = 10;
	
	e2x += o2x;
	e2y += o2y;
}

void estrellas_3(float e3x, float e3y, BITMAP *buffer){
	line(buffer, e3x ,e3y-10,e3x-2.5,e3y-2.5, 0xFBFF00);
	line(buffer, e3x-2.5,e3y-2.5,e3x-10,e3y, 0xFBFF00);
	line(buffer, e3x-10,e3y,e3x-2.5,e3y+2.5, 0xFBFF00);
	line(buffer, e3x-2.5,e3y+2.5,e3x,e3y+10, 0xFBFF00);
	line(buffer, e3x,e3y+10,e3x+2.5,e3y+2.5, 0xFBFF00);
	line(buffer, e3x+2.5,e3y+2.5,e3x+10,e3y, 0xFBFF00);
	line(buffer, e3x+10,e3y,e3x+2.5,e3y-2.5, 0xFBFF00);
	line(buffer, e3x+2.5,e3y-2.5,e3x ,e3y-10, 0xFBFF00);
}
void caida_estrellas_3(float &e3x, float &e3y, float &o3x, float &o3y){
	
	o3x = 0;
	o3y = 10;
	
	e3x += o3x;
	e3y += o3y;
}

void estrellas_4(float e4x, float e4y, BITMAP *buffer){
	line(buffer, e4x ,e4y-10,e4x-2.5,e4y-2.5, 0xFBFF00);
	line(buffer, e4x-2.5,e4y-2.5,e4x-10,e4y, 0xFBFF00);
	line(buffer, e4x-10,e4y,e4x-2.5,e4y+2.5, 0xFBFF00);
	line(buffer, e4x-2.5,e4y+2.5,e4x,e4y+10, 0xFBFF00);
	line(buffer, e4x,e4y+10,e4x+2.5,e4y+2.5, 0xFBFF00);
	line(buffer, e4x+2.5,e4y+2.5,e4x+10,e4y, 0xFBFF00);
	line(buffer, e4x+10,e4y,e4x+2.5,e4y-2.5, 0xFBFF00);
	line(buffer, e4x+2.5,e4y-2.5,e4x ,e4y-10, 0xFBFF00);
}
void caida_estrellas_4(float &e4x, float &e4y, float &o4x, float &o4y){
	
	o4x = 0;
	o4y = 10;
	
	e4x += o4x;
	e4y += o4y;
}

void estrellas_5(float e5x, float e5y, BITMAP *buffer){
	line(buffer, e5x ,e5y-10,e5x-2.5,e5y-2.5, 0xFBFF00);
	line(buffer, e5x-2.5,e5y-2.5,e5x-10,e5y, 0xFBFF00);
	line(buffer, e5x-10,e5y,e5x-2.5,e5y+2.5, 0xFBFF00);
	line(buffer, e5x-2.5,e5y+2.5,e5x,e5y+10, 0xFBFF00);
	line(buffer, e5x,e5y+10,e5x+2.5,e5y+2.5, 0xFBFF00);
	line(buffer, e5x+2.5,e5y+2.5,e5x+10,e5y, 0xFBFF00);
	line(buffer, e5x+10,e5y,e5x+2.5,e5y-2.5, 0xFBFF00);
	line(buffer, e5x+2.5,e5y-2.5,e5x ,e5y-10, 0xFBFF00);
	
}
void caida_estrellas_5(float &e5x, float &e5y, float &o5x, float &o5y){
	
	o5x = 0;
	o5y = 10;
	
	e5x += o5x;
	e5y += o5y;
}

void estrellas_6(float e6x, float e6y, BITMAP *buffer){
	line(buffer, e6x ,e6y-10,e6x-2.5,e6y-2.5, 0xFBFF00);
	line(buffer, e6x-2.5,e6y-2.5,e6x-10,e6y, 0xFBFF00);
	line(buffer, e6x-10,e6y,e6x-2.5,e6y+2.5, 0xFBFF00);
	line(buffer, e6x-2.5,e6y+2.5,e6x,e6y+10, 0xFBFF00);
	line(buffer, e6x,e6y+10,e6x+2.5,e6y+2.5, 0xFBFF00);
	line(buffer, e6x+2.5,e6y+2.5,e6x+10,e6y, 0xFBFF00);
	line(buffer, e6x+10,e6y,e6x+2.5,e6y-2.5, 0xFBFF00);
	line(buffer, e6x+2.5,e6y-2.5,e6x ,e6y-10, 0xFBFF00);
	
}
void caida_estrellas_6(float &e6x, float &e6y, float &o6x, float &o6y){
	
	o6x = 0;
	o6y = 10;
	
	e6x += o6x;
	e6y += o6y;
	
}

void estrellas_7(float e7x, float e7y, BITMAP *buffer){
	line(buffer, e7x ,e7y-10,e7x-2.5,e7y-2.5, 0xFBFF00);
	line(buffer, e7x-2.5,e7y-2.5,e7x-10,e7y, 0xFBFF00);
	line(buffer, e7x-10,e7y,e7x-2.5,e7y+2.5, 0xFBFF00);
	line(buffer, e7x-2.5,e7y+2.5,e7x,e7y+10, 0xFBFF00);
	line(buffer, e7x,e7y+10,e7x+2.5,e7y+2.5, 0xFBFF00);
	line(buffer, e7x+2.5,e7y+2.5,e7x+10,e7y, 0xFBFF00);
	line(buffer, e7x+10,e7y,e7x+2.5,e7y-2.5, 0xFBFF00);
	line(buffer, e7x+2.5,e7y-2.5,e7x ,e7y-10, 0xFBFF00);
	
}
void caida_estrellas_7(float &e7x, float &e7y, float &o7x, float &o7y){
	
	o7x = 0;
	o7y = 10;
	
	e7x += o7x;
	e7y += o7y;
}

void estrellas_8(float e8x, float e8y, BITMAP *buffer){
	line(buffer, e8x ,e8y-10,e8x-2.5,e8y-2.5, 0xFBFF00);
	line(buffer, e8x-2.5,e8y-2.5,e8x-10,e8y, 0xFBFF00);
	line(buffer, e8x-10,e8y,e8x-2.5,e8y+2.5, 0xFBFF00);
	line(buffer, e8x-2.5,e8y+2.5,e8x,e8y+10, 0xFBFF00);
	line(buffer, e8x,e8y+10,e8x+2.5,e8y+2.5, 0xFBFF00);
	line(buffer, e8x+2.5,e8y+2.5,e8x+10,e8y, 0xFBFF00);
	line(buffer, e8x+10,e8y,e8x+2.5,e8y-2.5, 0xFBFF00);
	line(buffer, e8x+2.5,e8y-2.5,e8x ,e8y-10, 0xFBFF00);
}
void caida_estrellas_8(float &e8x, float &e8y, float &o8x, float &o8y){
	
	
	o8x = 0;
	o8y = 10;
	
	e8x += o8x;
	e8y += o8y;
}
void caida_nave5(float &cx5, float &cy5, float &vx5, float &vy5){
	float ax, ay;
	ax = 0;
	ay = 0.03;
	
	vx5 += ax;
	vy5 += ay;
	
	cx5 += vx5;
	cy5 += vy5;
}
void rotar5(float &x, float &y, float cx, float cy, float da){ 
	float dx = x-cx;
	float dy = y-cy;
	float r = sqrt(dx*dx + dy*dy);
	float a = atan2(dy, dx);
	
	
	float da_rad = da/180 * M_PI;
	a -= da_rad;
	x = cx + r*cos(a);
	y = cy + r*sin(a);
}
void aceleracion5(float da, float &vx5, float &vy5){
	float ax = 0;
	float ay = -0.45;
	rotar5(ax, ay, 0, 0, da); 
	vx5 += ax;
	vy5 += ay;
}


void tiempo(bool tiempo_corriendo, float &tiempo_restante, BITMAP *buffer){
	textout_centre_ex(buffer, font, "TIEMPO", 480, 30, 0x999999, 0x000000);
	rectfill(buffer, 200, 50, 200+tiempo_restante, 70 ,0xFF00FB);
	if (tiempo_corriendo == true){
		tiempo_restante-=0.08673;
	}
}

void vida1(float vida1_x , float vida1_y , BITMAP *buffer){
	
	line(buffer, vida1_x-5,vida1_y+5,vida1_x+5,vida1_y+5, 0x64FF00);
	line(buffer, vida1_x+5,vida1_y+5,vida1_x+15,vida1_y, 0x64FF00);
	line(buffer, vida1_x-5,vida1_y+5,vida1_x-15,vida1_y, 0x64FF00);
	line(buffer, vida1_x-15,vida1_y,vida1_x-10,vida1_y-10, 0x64FF00);
	line(buffer, vida1_x-10,vida1_y-10,vida1_x-5,vida1_y-15, 0x64FF00);
	line(buffer, vida1_x-5,vida1_y-15,vida1_x+5,vida1_y-15, 0x64FF00);
	line(buffer, vida1_x+5,vida1_y-15,vida1_x+10,vida1_y-10, 0x64FF00);
	line(buffer, vida1_x+10,vida1_y-10,vida1_x+15,vida1_y, 0x64FF00);
	line(buffer, vida1_x-15,vida1_y,vida1_x-20,vida1_y+5, 0x64FF00);
	line(buffer, vida1_x+15,vida1_y,vida1_x+20,vida1_y+5, 0x64FF00);
	line(buffer, vida1_x-20,vida1_y+5,vida1_x-25,vida1_y+15, 0x64FF00);
	line(buffer, vida1_x-25,vida1_y+15,vida1_x-25,vida1_y+25, 0x64FF00);
	line(buffer, vida1_x-25,vida1_y+25,vida1_x-20,vida1_y+30, 0x64FF00);
	line(buffer, vida1_x-20,vida1_y+30,vida1_x-15,vida1_y+30, 0x64FF00);
	line(buffer, vida1_x-15,vida1_y+30,vida1_x-10,vida1_y+25, 0x64FF00);
	line(buffer, vida1_x-10,vida1_y+25,vida1_x-5,vida1_y+35, 0x64FF00);
	line(buffer, vida1_x-5,vida1_y+35,vida1_x+5,vida1_y+35, 0x64FF00);
	line(buffer, vida1_x+5,vida1_y+35,vida1_x+10,vida1_y+25, 0x64FF00);
	line(buffer, vida1_x+10,vida1_y+25,vida1_x+15,vida1_y+30, 0x64FF00);
	line(buffer, vida1_x+15,vida1_y+30,vida1_x+20,vida1_y+30, 0x64FF00);
	line(buffer, vida1_x+20,vida1_y+30,vida1_x+25,vida1_y+25, 0x64FF00);
	line(buffer, vida1_x+25,vida1_y+25,vida1_x+25,vida1_y+15, 0x64FF00);
	line(buffer, vida1_x+25,vida1_y+15,vida1_x+20,vida1_y+5, 0x64FF00);
	line(buffer, vida1_x-20,vida1_y+5,vida1_x-5,vida1_y+15, 0x64FF00);
	line(buffer, vida1_x-5,vida1_y+15,vida1_x+5,vida1_y+15, 0x64FF00);
	line(buffer, vida1_x+5,vida1_y+15,vida1_x+20,vida1_y+5, 0x64FF00);

}

void vida2(float vida2_x , float vida2_y , BITMAP *buffer){
	
	line(buffer, vida2_x-5,vida2_y+5,vida2_x+5,vida2_y+5, 0x64FF00);
	line(buffer, vida2_x+5,vida2_y+5,vida2_x+15,vida2_y, 0x64FF00);
	line(buffer, vida2_x-5,vida2_y+5,vida2_x-15,vida2_y, 0x64FF00);
	line(buffer, vida2_x-15,vida2_y,vida2_x-10,vida2_y-10, 0x64FF00);
	line(buffer, vida2_x-10,vida2_y-10,vida2_x-5,vida2_y-15, 0x64FF00);
	line(buffer, vida2_x-5,vida2_y-15,vida2_x+5,vida2_y-15, 0x64FF00);
	line(buffer, vida2_x+5,vida2_y-15,vida2_x+10,vida2_y-10, 0x64FF00);
	line(buffer, vida2_x+10,vida2_y-10,vida2_x+15,vida2_y, 0x64FF00);
	line(buffer, vida2_x-15,vida2_y,vida2_x-20,vida2_y+5, 0x64FF00);
	line(buffer, vida2_x+15,vida2_y,vida2_x+20,vida2_y+5, 0x64FF00);
	line(buffer, vida2_x-20,vida2_y+5,vida2_x-25,vida2_y+15, 0x64FF00);
	line(buffer, vida2_x-25,vida2_y+15,vida2_x-25,vida2_y+25, 0x64FF00);
	line(buffer, vida2_x-25,vida2_y+25,vida2_x-20,vida2_y+30, 0x64FF00);
	line(buffer, vida2_x-20,vida2_y+30,vida2_x-15,vida2_y+30, 0x64FF00);
	line(buffer, vida2_x-15,vida2_y+30,vida2_x-10,vida2_y+25, 0x64FF00);
	line(buffer, vida2_x-10,vida2_y+25,vida2_x-5,vida2_y+35, 0x64FF00);
	line(buffer, vida2_x-5,vida2_y+35,vida2_x+5,vida2_y+35, 0x64FF00);
	line(buffer, vida2_x+5,vida2_y+35,vida2_x+10,vida2_y+25, 0x64FF00);
	line(buffer, vida2_x+10,vida2_y+25,vida2_x+15,vida2_y+30, 0x64FF00);
	line(buffer, vida2_x+15,vida2_y+30,vida2_x+20,vida2_y+30, 0x64FF00);
	line(buffer, vida2_x+20,vida2_y+30,vida2_x+25,vida2_y+25, 0x64FF00);
	line(buffer, vida2_x+25,vida2_y+25,vida2_x+25,vida2_y+15, 0x64FF00);
	line(buffer, vida2_x+25,vida2_y+15,vida2_x+20,vida2_y+5, 0x64FF00);
	line(buffer, vida2_x-20,vida2_y+5,vida2_x-5,vida2_y+15, 0x64FF00);
	line(buffer, vida2_x-5,vida2_y+15,vida2_x+5,vida2_y+15, 0x64FF00);
	line(buffer, vida2_x+5,vida2_y+15,vida2_x+20,vida2_y+5, 0x64FF00);

}

void vida3(float vida3_x , float vida3_y , BITMAP *buffer){
	
	line(buffer, vida3_x-5,vida3_y+5,vida3_x+5,vida3_y+5, 0x64FF00);
	line(buffer, vida3_x+5,vida3_y+5,vida3_x+15,vida3_y, 0x64FF00);
	line(buffer, vida3_x-5,vida3_y+5,vida3_x-15,vida3_y, 0x64FF00);
	line(buffer, vida3_x-15,vida3_y,vida3_x-10,vida3_y-10, 0x64FF00);
	line(buffer, vida3_x-10,vida3_y-10,vida3_x-5,vida3_y-15, 0x64FF00);
	line(buffer, vida3_x-5,vida3_y-15,vida3_x+5,vida3_y-15, 0x64FF00);
	line(buffer, vida3_x+5,vida3_y-15,vida3_x+10,vida3_y-10, 0x64FF00);
	line(buffer, vida3_x+10,vida3_y-10,vida3_x+15,vida3_y, 0x64FF00);
	line(buffer, vida3_x-15,vida3_y,vida3_x-20,vida3_y+5, 0x64FF00);
	line(buffer, vida3_x+15,vida3_y,vida3_x+20,vida3_y+5, 0x64FF00);
	line(buffer, vida3_x-20,vida3_y+5,vida3_x-25,vida3_y+15, 0x64FF00);
	line(buffer, vida3_x-25,vida3_y+15,vida3_x-25,vida3_y+25, 0x64FF00);
	line(buffer, vida3_x-25,vida3_y+25,vida3_x-20,vida3_y+30, 0x64FF00);
	line(buffer, vida3_x-20,vida3_y+30,vida3_x-15,vida3_y+30, 0x64FF00);
	line(buffer, vida3_x-15,vida3_y+30,vida3_x-10,vida3_y+25, 0x64FF00);
	line(buffer, vida3_x-10,vida3_y+25,vida3_x-5,vida3_y+35, 0x64FF00);
	line(buffer, vida3_x-5,vida3_y+35,vida3_x+5,vida3_y+35, 0x64FF00);
	line(buffer, vida3_x+5,vida3_y+35,vida3_x+10,vida3_y+25, 0x64FF00);
	line(buffer, vida3_x+10,vida3_y+25,vida3_x+15,vida3_y+30, 0x64FF00);
	line(buffer, vida3_x+15,vida3_y+30,vida3_x+20,vida3_y+30, 0x64FF00);
	line(buffer, vida3_x+20,vida3_y+30,vida3_x+25,vida3_y+25, 0x64FF00);
	line(buffer, vida3_x+25,vida3_y+25,vida3_x+25,vida3_y+15, 0x64FF00);
	line(buffer, vida3_x+25,vida3_y+15,vida3_x+20,vida3_y+5, 0x64FF00);
	line(buffer, vida3_x-20,vida3_y+5,vida3_x-5,vida3_y+15, 0x64FF00);
	line(buffer, vida3_x-5,vida3_y+15,vida3_x+5,vida3_y+15, 0x64FF00);
	line(buffer, vida3_x+5,vida3_y+15,vida3_x+20,vida3_y+5, 0x64FF00);

}

void meteoritos_1(float m1x, float m1y, BITMAP *buffer){
	line(buffer, m1x-5,m1y-15,m1x+5,m1y-15, 0x00FFFB);
	line(buffer, m1x+5,m1y-15,m1x+15,m1y-5, 0x00FFFB);
	line(buffer, m1x+15,m1y-5,m1x+15,m1y+5, 0x00FFFB);
	line(buffer, m1x+15,m1y+5,m1x+5,m1y+15, 0x00FFFB);
	line(buffer, m1x+15,m1y+5,m1x+5,m1y+15, 0x00FFFB);
	line(buffer, m1x+5,m1y+15,m1x-5,m1y+15, 0x00FFFB);
	line(buffer, m1x-5,m1y+15,m1x-15,m1y+5, 0x00FFFB);
	line(buffer, m1x-15,m1y+5,m1x-15,m1y-5, 0x00FFFB);
	line(buffer, m1x-15,m1y-5,m1x-5,m1y-15, 0x00FFFB);
	line(buffer, m1x-5,m1y-10,m1x-15,m1y-20, 0x00FFFB);
	line(buffer, m1x+5,m1y-10,m1x+15,m1y-20, 0x00FFFB);
	line(buffer, m1x+10,m1y-5,m1x+20,m1y-5, 0x00FFFB);
	line(buffer, m1x+10,m1y+5,m1x+20,m1y+5, 0x00FFFB);
	line(buffer, m1x+5,m1y+10,m1x+15,m1y+20, 0x00FFFB);
	line(buffer, m1x-5,m1y+10,m1x-15,m1y+20, 0x00FFFB);
	line(buffer, m1x-10,m1y+5,m1x-20,m1y+5, 0x00FFFB);
	line(buffer, m1x-10,m1y-5,m1x-20,m1y-5, 0x00FFFB);
	line(buffer, m1x-5,m1y-10,m1x-5,m1y+10, 0x00FFFB);
	line(buffer, m1x+5,m1y-10,m1x+5,m1y+10, 0x00FFFB);
	line(buffer, m1x-10,m1y-5,m1x+10,m1y-5, 0x00FFFB);
	line(buffer, m1x-10,m1y+5,m1x+20,m1y+5, 0x00FFFB);
} 
void caida_meteoritos_1(float &m1x, float &m1y, float &n1x, float &n1y){
	
	float ac1y, ac1x;
	
	ac1x = 0;
	ac1y = 0.0010;
	
	n1x += 0;
	n1y += ac1y;
	
	m1x += n1x;
	m1y += n1y;
}

void meteoritos_2(float m2x, float m2y, BITMAP *buffer){
	line(buffer, m2x-5,m2y-15,m2x+5,m2y-15, 0x00FFFB);
	line(buffer, m2x+5,m2y-15,m2x+15,m2y-5, 0x00FFFB);
	line(buffer, m2x+15,m2y-5,m2x+15,m2y+5, 0x00FFFB);
	line(buffer, m2x+15,m2y+5,m2x+5,m2y+15, 0x00FFFB);
	line(buffer, m2x+15,m2y+5,m2x+5,m2y+15, 0x00FFFB);
	line(buffer, m2x+5,m2y+15,m2x-5,m2y+15, 0x00FFFB);
	line(buffer, m2x-5,m2y+15,m2x-15,m2y+5, 0x00FFFB);
	line(buffer, m2x-15,m2y+5,m2x-15,m2y-5, 0x00FFFB);
	line(buffer, m2x-15,m2y-5,m2x-5,m2y-15, 0x00FFFB);
	line(buffer, m2x-5,m2y-10,m2x-15,m2y-20, 0x00FFFB);
	line(buffer, m2x+5,m2y-10,m2x+15,m2y-20, 0x00FFFB);
	line(buffer, m2x+10,m2y-5,m2x+20,m2y-5, 0x00FFFB);
	line(buffer, m2x+10,m2y+5,m2x+20,m2y+5, 0x00FFFB);
	line(buffer, m2x+5,m2y+10,m2x+15,m2y+20, 0x00FFFB);
	line(buffer, m2x-5,m2y+10,m2x-15,m2y+20, 0x00FFFB);
	line(buffer, m2x-10,m2y+5,m2x-20,m2y+5, 0x00FFFB);
	line(buffer, m2x-10,m2y-5,m2x-20,m2y-5, 0x00FFFB);
	line(buffer, m2x-5,m2y-10,m2x-5,m2y+10, 0x00FFFB);
	line(buffer, m2x+5,m2y-10,m2x+5,m2y+10, 0x00FFFB);
	line(buffer, m2x-10,m2y-5,m2x+10,m2y-5, 0x00FFFB);
	line(buffer, m2x-10,m2y+5,m2x+20,m2y+5, 0x00FFFB);
}
void caida_meteoritos_2(float &m2x, float &m2y, float &n2x, float &n2y){
	
	float ac2x, ac2y;
	
	ac2x = 0;
	ac2y = 0.0010;
	
	n2x += ac2x;
	n2y += ac2y;

	m2x += n2x;
	m2y += n2y;
	
}

void meteoritos_3(float m3x, float m3y, BITMAP *buffer){
	line(buffer, m3x-5,m3y-15,m3x+5,m3y-15, 0x00FFFB);
	line(buffer, m3x+5,m3y-15,m3x+15,m3y-5, 0x00FFFB);
	line(buffer, m3x+15,m3y-5,m3x+15,m3y+5, 0x00FFFB);
	line(buffer, m3x+15,m3y+5,m3x+5,m3y+15, 0x00FFFB);
	line(buffer, m3x+15,m3y+5,m3x+5,m3y+15, 0x00FFFB);
	line(buffer, m3x+5,m3y+15,m3x-5,m3y+15, 0x00FFFB);
	line(buffer, m3x-5,m3y+15,m3x-15,m3y+5, 0x00FFFB);
	line(buffer, m3x-15,m3y+5,m3x-15,m3y-5, 0x00FFFB);
	line(buffer, m3x-15,m3y-5,m3x-5,m3y-15, 0x00FFFB);
	line(buffer, m3x-5,m3y-10,m3x-15,m3y-20, 0x00FFFB);
	line(buffer, m3x+5,m3y-10,m3x+15,m3y-20, 0x00FFFB);
	line(buffer, m3x+10,m3y-5,m3x+20,m3y-5, 0x00FFFB);
	line(buffer, m3x+10,m3y+5,m3x+20,m3y+5, 0x00FFFB);
	line(buffer, m3x+5,m3y+10,m3x+15,m3y+20, 0x00FFFB);
	line(buffer, m3x-5,m3y+10,m3x-15,m3y+20, 0x00FFFB);
	line(buffer, m3x-10,m3y+5,m3x-20,m3y+5, 0x00FFFB);
	line(buffer, m3x-10,m3y-5,m3x-20,m3y-5, 0x00FFFB);
	line(buffer, m3x-5,m3y-10,m3x-5,m3y+10, 0x00FFFB);
	line(buffer, m3x+5,m3y-10,m3x+5,m3y+10, 0x00FFFB);
	line(buffer, m3x-10,m3y-5,m3x+10,m3y-5, 0x00FFFB);
	line(buffer, m3x-10,m3y+5,m3x+20,m3y+5, 0x00FFFB);
} 
void caida_meteoritos_3(float &m3x, float &m3y, float &n3x, float &n3y){
	
	float ac3x, ac3y;
	
	ac3x = 0;
	ac3y = 0.0010;
	
	n3x += ac3x;
	n3y += ac3y;
	
	m3x += n3x;
	m3y += n3y;
}

void meteoritos_4(float m4x, float m4y, BITMAP *buffer){
	line(buffer, m4x-5,m4y-15,m4x+5,m4y-15, 0x00FFFB);
	line(buffer, m4x+5,m4y-15,m4x+15,m4y-5, 0x00FFFB);
	line(buffer, m4x+15,m4y-5,m4x+15,m4y+5, 0x00FFFB);
	line(buffer, m4x+15,m4y+5,m4x+5,m4y+15, 0x00FFFB);
	line(buffer, m4x+15,m4y+5,m4x+5,m4y+15, 0x00FFFB);
	line(buffer, m4x+5,m4y+15,m4x-5,m4y+15, 0x00FFFB);
	line(buffer, m4x-5,m4y+15,m4x-15,m4y+5, 0x00FFFB);
	line(buffer, m4x-15,m4y+5,m4x-15,m4y-5, 0x00FFFB);
	line(buffer, m4x-15,m4y-5,m4x-5,m4y-15, 0x00FFFB);
	line(buffer, m4x-5,m4y-10,m4x-15,m4y-20, 0x00FFFB);
	line(buffer, m4x+5,m4y-10,m4x+15,m4y-20, 0x00FFFB);
	line(buffer, m4x+10,m4y-5,m4x+20,m4y-5, 0x00FFFB);
	line(buffer, m4x+10,m4y+5,m4x+20,m4y+5, 0x00FFFB);
	line(buffer, m4x+5,m4y+10,m4x+15,m4y+20, 0x00FFFB);
	line(buffer, m4x-5,m4y+10,m4x-15,m4y+20, 0x00FFFB);
	line(buffer, m4x-10,m4y+5,m4x-20,m4y+5, 0x00FFFB);
	line(buffer, m4x-10,m4y-5,m4x-20,m4y-5, 0x00FFFB);
	line(buffer, m4x-5,m4y-10,m4x-5,m4y+10, 0x00FFFB);
	line(buffer, m4x+5,m4y-10,m4x+5,m4y+10, 0x00FFFB);
	line(buffer, m4x-10,m4y-5,m4x+10,m4y-5, 0x00FFFB);
	line(buffer, m4x-10,m4y+5,m4x+20,m4y+5, 0x00FFFB);
}
void caida_meteoritos_4(float &m4x, float &m4y, float &n4x, float &n4y){
	
	float ac4x, ac4y;
	
	ac4x = 0;
	ac4y = 0.0010;
	
	n4x += ac4x;
	n4y += ac4y;
	
	m4x += n4x;
	m4y += n4y;
}

void meteoritos_5(float m5x, float m5y, BITMAP *buffer){
	line(buffer, m5x-5,m5y-15,m5x+5,m5y-15, 0x00FFFB);
	line(buffer, m5x+5,m5y-15,m5x+15,m5y-5, 0x00FFFB);
	line(buffer, m5x+15,m5y-5,m5x+15,m5y+5, 0x00FFFB);
	line(buffer, m5x+15,m5y+5,m5x+5,m5y+15, 0x00FFFB);
	line(buffer, m5x+15,m5y+5,m5x+5,m5y+15, 0x00FFFB);
	line(buffer, m5x+5,m5y+15,m5x-5,m5y+15, 0x00FFFB);
	line(buffer, m5x-5,m5y+15,m5x-15,m5y+5, 0x00FFFB);
	line(buffer, m5x-15,m5y+5,m5x-15,m5y-5, 0x00FFFB);
	line(buffer, m5x-15,m5y-5,m5x-5,m5y-15, 0x00FFFB);
	line(buffer, m5x-5,m5y-10,m5x-15,m5y-20, 0x00FFFB);
	line(buffer, m5x+5,m5y-10,m5x+15,m5y-20, 0x00FFFB);
	line(buffer, m5x+10,m5y-5,m5x+20,m5y-5, 0x00FFFB);
	line(buffer, m5x+10,m5y+5,m5x+20,m5y+5, 0x00FFFB);
	line(buffer, m5x+5,m5y+10,m5x+15,m5y+20, 0x00FFFB);
	line(buffer, m5x-5,m5y+10,m5x-15,m5y+20, 0x00FFFB);
	line(buffer, m5x-10,m5y+5,m5x-20,m5y+5, 0x00FFFB);
	line(buffer, m5x-10,m5y-5,m5x-20,m5y-5, 0x00FFFB);
	line(buffer, m5x-5,m5y-10,m5x-5,m5y+10, 0x00FFFB);
	line(buffer, m5x+5,m5y-10,m5x+5,m5y+10, 0x00FFFB);
	line(buffer, m5x-10,m5y-5,m5x+10,m5y-5, 0x00FFFB);
	line(buffer, m5x-10,m5y+5,m5x+20,m5y+5, 0x00FFFB);
}
void caida_meteoritos_5(float &m5x, float &m5y, float &n5x, float &n5y){
	
	float ac5x, ac5y;
	
	ac5x = 0;
	ac5y = 0.0010;
	
	n5x += ac5x;
	n5y += ac5y;
	
	m5x += n5x;
	m5y += n5y;
}

void meteoritos_6(float m6x, float m6y, BITMAP *buffer){
	line(buffer, m6x-5,m6y-15,m6x+5,m6y-15, 0x00FFFB);
	line(buffer, m6x+5,m6y-15,m6x+15,m6y-5, 0x00FFFB);
	line(buffer, m6x+15,m6y-5,m6x+15,m6y+5, 0x00FFFB);
	line(buffer, m6x+15,m6y+5,m6x+5,m6y+15, 0x00FFFB);
	line(buffer, m6x+15,m6y+5,m6x+5,m6y+15, 0x00FFFB);
	line(buffer, m6x+5,m6y+15,m6x-5,m6y+15, 0x00FFFB);
	line(buffer, m6x-5,m6y+15,m6x-15,m6y+5, 0x00FFFB);
	line(buffer, m6x-15,m6y+5,m6x-15,m6y-5, 0x00FFFB);
	line(buffer, m6x-15,m6y-5,m6x-5,m6y-15, 0x00FFFB);
	line(buffer, m6x-5,m6y-10,m6x-15,m6y-20, 0x00FFFB);
	line(buffer, m6x+5,m6y-10,m6x+15,m6y-20, 0x00FFFB);
	line(buffer, m6x+10,m6y-5,m6x+20,m6y-5, 0x00FFFB);
	line(buffer, m6x+10,m6y+5,m6x+20,m6y+5, 0x00FFFB);
	line(buffer, m6x+5,m6y+10,m6x+15,m6y+20, 0x00FFFB);
	line(buffer, m6x-5,m6y+10,m6x-15,m6y+20, 0x00FFFB);
	line(buffer, m6x-10,m6y+5,m6x-20,m6y+5, 0x00FFFB);
	line(buffer, m6x-10,m6y-5,m6x-20,m6y-5, 0x00FFFB);
	line(buffer, m6x-5,m6y-10,m6x-5,m6y+10, 0x00FFFB);
	line(buffer, m6x+5,m6y-10,m6x+5,m6y+10, 0x00FFFB);
	line(buffer, m6x-10,m6y-5,m6x+10,m6y-5, 0x00FFFB);
	line(buffer, m6x-10,m6y+5,m6x+20,m6y+5, 0x00FFFB);
}
void caida_meteoritos_6(float &m6x, float &m6y, float &n6x, float &n6y){
	
	float ac6x, ac6y;
	
	ac6x = 0;
	ac6y = 0.0010;
	
	n6x += ac6x;
	n6y += ac6y;
	
	m6x += n6x;
	m6y += n6y;
}

void meteoritos_7(float m7x, float m7y, BITMAP *buffer){
	line(buffer, m7x-5,m7y-15,m7x+5,m7y-15, 0x00FFFB);
	line(buffer, m7x+5,m7y-15,m7x+15,m7y-5, 0x00FFFB);
	line(buffer, m7x+15,m7y-5,m7x+15,m7y+5, 0x00FFFB);
	line(buffer, m7x+15,m7y+5,m7x+5,m7y+15, 0x00FFFB);
	line(buffer, m7x+15,m7y+5,m7x+5,m7y+15, 0x00FFFB);
	line(buffer, m7x+5,m7y+15,m7x-5,m7y+15, 0x00FFFB);
	line(buffer, m7x-5,m7y+15,m7x-15,m7y+5, 0x00FFFB);
	line(buffer, m7x-15,m7y+5,m7x-15,m7y-5, 0x00FFFB);
	line(buffer, m7x-15,m7y-5,m7x-5,m7y-15, 0x00FFFB);
	line(buffer, m7x-5,m7y-10,m7x-15,m7y-20, 0x00FFFB);
	line(buffer, m7x+5,m7y-10,m7x+15,m7y-20, 0x00FFFB);
	line(buffer, m7x+10,m7y-5,m7x+20,m7y-5, 0x00FFFB);
	line(buffer, m7x+10,m7y+5,m7x+20,m7y+5, 0x00FFFB);
	line(buffer, m7x+5,m7y+10,m7x+15,m7y+20, 0x00FFFB);
	line(buffer, m7x-5,m7y+10,m7x-15,m7y+20, 0x00FFFB);
	line(buffer, m7x-10,m7y+5,m7x-20,m7y+5, 0x00FFFB);
	line(buffer, m7x-10,m7y-5,m7x-20,m7y-5, 0x00FFFB);
	line(buffer, m7x-5,m7y-10,m7x-5,m7y+10, 0x00FFFB);
	line(buffer, m7x+5,m7y-10,m7x+5,m7y+10, 0x00FFFB);
	line(buffer, m7x-10,m7y-5,m7x+10,m7y-5, 0x00FFFB);
	line(buffer, m7x-10,m7y+5,m7x+20,m7y+5, 0x00FFFB);

}
void caida_meteoritos_7(float &m7x, float &m7y, float &n7x, float &n7y){
	
	float ac7x, ac7y;
	
	ac7x = 0;
	ac7y = 0.0010;
	
	n7x += ac7x;
	n7y += ac7y;
	
	m7x += n7x;
	m7y += n7y;
}

void meteoritos_8(float m8x, float m8y, BITMAP *buffer){
	line(buffer, m8x-5,m8y-15,m8x+5,m8y-15, 0x00FFFB);
	line(buffer, m8x+5,m8y-15,m8x+15,m8y-5, 0x00FFFB);
	line(buffer, m8x+15,m8y-5,m8x+15,m8y+5, 0x00FFFB);
	line(buffer, m8x+15,m8y+5,m8x+5,m8y+15, 0x00FFFB);
	line(buffer, m8x+15,m8y+5,m8x+5,m8y+15, 0x00FFFB);
	line(buffer, m8x+5,m8y+15,m8x-5,m8y+15, 0x00FFFB);
	line(buffer, m8x-5,m8y+15,m8x-15,m8y+5, 0x00FFFB);
	line(buffer, m8x-15,m8y+5,m8x-15,m8y-5, 0x00FFFB);
	line(buffer, m8x-15,m8y-5,m8x-5,m8y-15, 0x00FFFB);
	line(buffer, m8x-5,m8y-10,m8x-15,m8y-20, 0x00FFFB);
	line(buffer, m8x+5,m8y-10,m8x+15,m8y-20, 0x00FFFB);
	line(buffer, m8x+10,m8y-5,m8x+20,m8y-5, 0x00FFFB);
	line(buffer, m8x+10,m8y+5,m8x+20,m8y+5, 0x00FFFB);
	line(buffer, m8x+5,m8y+10,m8x+15,m8y+20, 0x00FFFB);
	line(buffer, m8x-5,m8y+10,m8x-15,m8y+20, 0x00FFFB);
	line(buffer, m8x-10,m8y+5,m8x-20,m8y+5, 0x00FFFB);
	line(buffer, m8x-10,m8y-5,m8x-20,m8y-5, 0x00FFFB);
	line(buffer, m8x-5,m8y-10,m8x-5,m8y+10, 0x00FFFB);
	line(buffer, m8x+5,m8y-10,m8x+5,m8y+10, 0x00FFFB);
	line(buffer, m8x-10,m8y-5,m8x+10,m8y-5, 0x00FFFB);
	line(buffer, m8x-10,m8y+5,m8x+20,m8y+5, 0x00FFFB);
} 
void caida_meteoritos_8(float &m8x, float &m8y, float &n8x, float &n8y){
	
	float ac8x, ac8y;
	
	ac8x = 0;
	ac8y = 0.0010;
	
	n8x += ac8x;
	n8y += ac8y;
	
	m8x += n8x;
	m8y += n8y;
}

void meteoritos_9(float m9x, float m9y, BITMAP *buffer){
	line(buffer, m9x-5,m9y-15,m9x+5,m9y-15, 0x00FFFB);
	line(buffer, m9x+5,m9y-15,m9x+15,m9y-5, 0x00FFFB);
	line(buffer, m9x+15,m9y-5,m9x+15,m9y+5, 0x00FFFB);
	line(buffer, m9x+15,m9y+5,m9x+5,m9y+15, 0x00FFFB);
	line(buffer, m9x+15,m9y+5,m9x+5,m9y+15, 0x00FFFB);
	line(buffer, m9x+5,m9y+15,m9x-5,m9y+15, 0x00FFFB);
	line(buffer, m9x-5,m9y+15,m9x-15,m9y+5, 0x00FFFB);
	line(buffer, m9x-15,m9y+5,m9x-15,m9y-5, 0x00FFFB);
	line(buffer, m9x-15,m9y-5,m9x-5,m9y-15, 0x00FFFB);
	line(buffer, m9x-5,m9y-10,m9x-15,m9y-20, 0x00FFFB);
	line(buffer, m9x+5,m9y-10,m9x+15,m9y-20, 0x00FFFB);
	line(buffer, m9x+10,m9y-5,m9x+20,m9y-5, 0x00FFFB);
	line(buffer, m9x+10,m9y+5,m9x+20,m9y+5, 0x00FFFB);
	line(buffer, m9x+5,m9y+10,m9x+15,m9y+20, 0x00FFFB);
	line(buffer, m9x-5,m9y+10,m9x-15,m9y+20, 0x00FFFB);
	line(buffer, m9x-10,m9y+5,m9x-20,m9y+5, 0x00FFFB);
	line(buffer, m9x-10,m9y-5,m9x-20,m9y-5, 0x00FFFB);
	line(buffer, m9x-5,m9y-10,m9x-5,m9y+10, 0x00FFFB);
	line(buffer, m9x+5,m9y-10,m9x+5,m9y+10, 0x00FFFB);
	line(buffer, m9x-10,m9y-5,m9x+10,m9y-5, 0x00FFFB);
	line(buffer, m9x-10,m9y+5,m9x+20,m9y+5, 0x00FFFB);
} 
void caida_meteoritos_9(float &m9x, float &m9y, float &n9x, float &n9y){
	
	float ac9x, ac9y;
	
	ac9x = 0;
	ac9y = 0.0010;
	
	n9x += ac9x;
	n9y += ac9y;
	
	m9x += n9x;
	m9y += n9y;
}

void meteoritos_10(float m10x, float m10y, BITMAP *buffer){
	line(buffer, m10x-5,m10y-15,m10x+5,m10y-15, 0x00FFFB);
	line(buffer, m10x+5,m10y-15,m10x+15,m10y-5, 0x00FFFB);
	line(buffer, m10x+15,m10y-5,m10x+15,m10y+5, 0x00FFFB);
	line(buffer, m10x+15,m10y+5,m10x+5,m10y+15, 0x00FFFB);
	line(buffer, m10x+15,m10y+5,m10x+5,m10y+15, 0x00FFFB);
	line(buffer, m10x+5,m10y+15,m10x-5,m10y+15, 0x00FFFB);
	line(buffer, m10x-5,m10y+15,m10x-15,m10y+5, 0x00FFFB);
	line(buffer, m10x-15,m10y+5,m10x-15,m10y-5, 0x00FFFB);
	line(buffer, m10x-15,m10y-5,m10x-5,m10y-15, 0x00FFFB);
	line(buffer, m10x-5,m10y-10,m10x-15,m10y-20, 0x00FFFB);
	line(buffer, m10x+5,m10y-10,m10x+15,m10y-20, 0x00FFFB);
	line(buffer, m10x+10,m10y-5,m10x+20,m10y-5, 0x00FFFB);
	line(buffer, m10x+10,m10y+5,m10x+20,m10y+5, 0x00FFFB);
	line(buffer, m10x+5,m10y+10,m10x+15,m10y+20, 0x00FFFB);
	line(buffer, m10x-5,m10y+10,m10x-15,m10y+20, 0x00FFFB);
	line(buffer, m10x-10,m10y+5,m10x-20,m10y+5, 0x00FFFB);
	line(buffer, m10x-10,m10y-5,m10x-20,m10y-5, 0x00FFFB);
	line(buffer, m10x-5,m10y-10,m10x-5,m10y+10, 0x00FFFB);
	line(buffer, m10x+5,m10y-10,m10x+5,m10y+10, 0x00FFFB);
	line(buffer, m10x-10,m10y-5,m10x+10,m10y-5, 0x00FFFB);
	line(buffer, m10x-10,m10y+5,m10x+20,m10y+5, 0x00FFFB);
}
void caida_meteoritos_10(float &m10x, float &m10y, float &n10x, float &n10y){
	
	float ac10x, ac10y;
	
	ac10x = 0;
	ac10y = 0.0010;
	
	n10x += ac10x;
	n10y += ac10y;
	
	m10x += n10x;
	m10y += n10y;
}


void barra_1(float &punto_inicio_1_x, float &punto_inicio_1_y, float &punto_final_1_x, float &punto_final_1_y, BITMAP *buffer){
	rectfill(buffer, punto_inicio_1_x, punto_inicio_1_y, punto_final_1_x, punto_final_1_y ,0x00FF36);
}

void caida_barra_1(float &punto_inicio_1_x, float &punto_inicio_1_y, float &punto_final_1_x, float &punto_final_1_y){
	
	float velocidad_a_1=5;
	float velocidad_a_2=5;
	
	punto_inicio_1_y += velocidad_a_1;
	punto_final_1_y += velocidad_a_2;
}

void barra_2(float &punto_inicio_2_x, float &punto_inicio_2_y, float &punto_final_2_x, float &punto_final_2_y, BITMAP *buffer){
	rectfill(buffer, punto_inicio_2_x, punto_inicio_2_y, punto_final_2_x, punto_final_2_y ,0xFF0000);
}

void caida_barra_2(float &punto_inicio_2_x, float &punto_inicio_2_y, float &punto_final_2_x, float &punto_final_2_y){
	
	float velocidad_b_1=5;
	float velocidad_b_2=5;
	
	punto_inicio_2_y += velocidad_b_1;
	punto_final_2_y += velocidad_b_2;
}

void barra_3(float &punto_inicio_3_x, float &punto_inicio_3_y, float &punto_final_3_x, float &punto_final_3_y, BITMAP *buffer){
	rectfill(buffer, punto_inicio_3_x, punto_inicio_3_y, punto_final_3_x, punto_final_3_y ,0xFFD100);
}

void caida_barra_3(float &punto_inicio_3_x, float &punto_inicio_3_y, float &punto_final_3_x, float &punto_final_3_y){
	
	float velocidad_c_1=5;
	float velocidad_c_2=5;
	
	punto_inicio_3_y += velocidad_c_1;
	punto_final_3_y += velocidad_c_2;
}
 
