#include <stdio.h>
#include <stdlib.h>
#include <string.h>

es_numerico(const char *p) {

if (*p) {

	char c;
	
	while((c=*p++)){	
		if (!isdigit(c)) return 0;
		} 

	return 1;
	
	}

return 0;

}
 
int main(int argc, char **argv) {

	// Variables globales
	int option;
	FILE *fichero;                 
	char password[254];

	// Variables para funcionalidad
	int funcionalidad;

	// Variables para control de acceso
	int acceso;

	// Variables para control de contraseñas
	char password1[254], password2[254];

	// Variables para validación de HW
	char strMacEth0[20], strMacEth1[20];	// strings para obtener las mac
	char strEth0[20], strEth1[20], *str; 	// strings auxiliares
	long long lMacEth0, lMacEth1;	// variables long para guardar las mac
	FILE *fp;
	long long valorcalculado, valorleido;	

	// Pregunta por la contraseña para proseguir
	printf("Password:");
	system("stty -echo");
	scanf("%s",password);
	system("stty echo");
	
	if ( !strcmp(password, "f0t0nica") ) {
	
		// MENÚ:
		// Pregunta qué desea hacer
		printf("\n\n### ITACA PROTECTED SETTINGS ###\n");
		printf("Choose an option:\n");
		printf("1 - Functionality\n");
		printf("2 - Access control\n");
		printf("3 - Passwords\n");
		printf("4 - Backup/Restore\n");
		printf("5 - Hardware validation\n");
		printf("6 - Print hardware validation data\n");
		printf("7 - Enter validation code\n");
		printf("8 - Table and slitting\n");
		printf("0 - Exit\n");
		printf("\n");
		
		scanf("%d",&option);

		// Procesa la opción seleccionada
		switch (option) {

		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Funcionalidad
		case 1:
				
			/* Pregunta qué funcionalidad se desea utilizar */
			printf("\n\nSelect:\n");
			printf("1 - 4 Lines - Text only\n");
			printf("2 - 4 Lines - Complete functionality: text, graphics and barcodes\n");
			printf("3 - 4 Lines with 3 data blocks per line - Complete functionality\n");
			printf("\n");
			scanf("%d",&funcionalidad);

			/* Crea el fichero */
			fichero = fopen("/root/itaca/funcionalidad.bin", "wb");

			switch (funcionalidad) {

			/* Sólo texto: escribe un 0 en binario */
			case 1:
				fputc(0,fichero);
				break;	

			/* Funcionalidad completa: escribe un 1 en binario */
			case 2:
        	       		fputc(1,fichero);
                		break;

			/* Bloques de datos en cada línea: escribe un 2 en binario */
			case 3:
        	       		fputc(2,fichero);
                		break;

			default:	
        	       		printf("\nIncorrect option\n");
                		break;
	
			}
		
			/* Cierra el fichero */
			fclose(fichero);

			/* Monta la partición en modo de escritura */
			system("mount / -o rw,remount");
		
			/* Copia el fichero en el directorio de carga */
			system("cp /root/itaca/funcionalidad.bin /rootFLS/itaca");

			/* Resetea los datos de marcaje */
			system("cp /root/itaca/itaca.dat.ok /root/itaca/itaca.dat");
			system("cp /rootFLS/itaca/itaca.dat.ok /rootFLS/itaca/itaca.dat");

			/* Monta la partición en modo de lectura */
			system("mount / -o ro,remount");
	
			/* Informa que ha terminado correctamente */
			printf("\nFunctionality changed OK\n");
			
			break;

		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Access control
		case 2:

			// Pregunta si se quiere activar o no el control de acceso
			printf("\n\nSelect:\n");
			printf("1 - Access control deactivated\n");
			printf("2 - Access control ACTIVATED\n");
			printf("\n");
			scanf("%d",&acceso);

			// Crea el fichero como un archivo nuevo
			fichero = fopen("/root/itaca/acceso.bin", "wb");

			switch (acceso) {

			// Desactivado: escribe un 1 en binario
			case 1:
				fputc(1,fichero);
				break;

			// Activado: escribe un 0 en binario
			case 2:
       	        		fputc(0,fichero);
               			break;

			default:
       	        		printf("\nIncorrect option\n");
               			break;

			}
		
			// Cierra el fichero
			fclose(fichero);

			// Monta la partición en modo de escritura
			system("mount / -o rw,remount");
		
			// Copia el fichero en el directorio de carga
			system("cp /root/itaca/acceso.bin /rootFLS/itaca");

			// Monta la partición en modo de lectura
			system("mount / -o ro,remount");
	
			// Informa que ha terminado correctamente
			printf("\nAccess control changed OK\n");

			break;

		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Passwords
		case 3:

			// Pregunta qué password se desea cambiar
			printf("\n\nSelect:\n");
			printf("1 - Change user password\n");
			printf("2 - Change configuration password\n");
			printf("3 - Restore default passwords\n");
			printf("\n");
	
			scanf("%d",&option);
			
			switch (option) {

			// Cambia la contraseña de usuario del ÍTACA
			case 1:
		
				printf("Write the new user password (up to 10 digits):\n");
				system("stty -echo");
				scanf("%10s", password1);
				system("stty echo");
		
				// Si no es numérico sale
				if (!es_numerico(password1)) {
					printf("The password contains invalid characters. Exit.\n");
					return 1;
				}
		
				printf("Write again the new user password (up to 10 digits):\n");
				system("stty -echo");
				scanf("%10s", password2);
				system("stty echo");	
		
				// Si no es numérico sale
				if (!es_numerico(password2)) {
					printf("The password contains invalid characters. Exit.\n");
					return 1;
				}
		
				// Si son iguales guarda la contraseña	
				if (strcmp(password1,password2) == 0) {
		
					// Monta la partición en modo de escritura
					system("mount / -o rw,remount");
	
					// Abre el archivo como un archivo nuevo
					fichero = fopen("/root/itaca/usuario.bin", "wb");
			
					// Escribe la contraseña en el fichero
					//fprintf(fichero, password1);
					fputs(password1, fichero);
			
					// Cierra el fichero
					fclose(fichero);
			
					// Copia el fichero en el directorio de carga
					system("cp /root/itaca/usuario.bin /rootFLS/itaca");
	
					// Monta la partición en modo de lectura
					system("mount / -o ro,remount");

					// Informa que ha terminado correctamente
					printf("User password changed OK\n");
			
				}
		
				else {
			
					// Ha introducido dos contraseñas distintas
					printf("The passwords are different. Exit.\n");
		
				}
		
				break;

			// Cambia la contraseña de configuración
			case 2:
       	        		
				printf("Write the new configuration password (up to 10 digits):\n");
				system("stty -echo");
				scanf("%10s", password1);
				system("stty echo");
		
				// Si no es numérico sale
				if (!es_numerico(password1)) {
					printf("The password contains invalid characters. Exit.\n");
					return 1;
				}
		
				printf("Write again the new configuration password (up to 10 digits):\n");
				system("stty -echo");
				scanf("%10s", password2);
				system("stty echo");
		
				// Si no es numérico sale
				if (!es_numerico(password2)) {
					printf("The password contains invalid characters. Exit.\n");
					return 1;
				}	
		
				// Si son iguales guarda la contraseña
				if (strcmp(password1,password2) == 0) {
					
					// Monta la partición en modo de escritura
					system("mount / -o rw,remount");
	
					// Abre el archivo como un archivo nuevo
					fichero = fopen("/root/itaca/configuracion.bin", "wb");
			
					// Escribe la contraseña en el fichero
					//fprintf(fichero, password1);
					fputs(password1, fichero);
			
					// Cierra el fichero
					fclose(fichero);
			
					// Copia el fichero en el directorio de carga
					system("cp /root/itaca/configuracion.bin /rootFLS/itaca");
		
					// Monta la partición en modo de lectura
					system("mount / -o ro,remount");

					// Informa que ha terminado correctamente
					printf("Configuration password changed OK\n");
			
				}
		
				else {
			
					// Ha introducido dos contraseñas distintas
					printf("The passwords are different. Exit.\n");
		
				}
		
	        		break;
               	
       			// Restaura las contraseñas por defecto, borrando los archivos de contraseñas
			case 3:
       	        
				// Monta la partición en modo de escritura
				system("mount / -o rw,remount");
	
				// Borra el archivo original de la contraseña de usuario si existe
				fichero = fopen("/root/itaca/usuario.bin", "r");
				if (fichero) {
					fclose(fichero);
					system("rm /root/itaca/usuario.bin");
					system("rm /rootFLS/itaca/usuario.bin");
				}
		
				// Borra el archivo original de la contraseña de configuracion si existe
				fichero = fopen("/root/itaca/configuracion.bin", "r");
				if (fichero) {
					fclose(fichero);
					system("rm /root/itaca/configuracion.bin");
					system("rm /rootFLS/itaca/configuracion.bin");
				}
				
				// Monta la partición en modo de lectura
				system("mount / -o ro,remount");	

				// Informa que ha terminado correctamente
				printf("Default passwords restored OK\n");
		
        			break;

			}

			break;
		
		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Backup/Restore
		case 4:

			// Pregunta qué se desea hacer
			printf("\n\nSelect:\n");
			printf("1 - Backup system data to usb service device\n");
			printf("2 - Restore system data from usb service device\n");
			printf("\n");
			scanf("%d",&option);

			switch (option)	{

			// Realizar backup
			case 1:
		
				// Copia el directorio /root/itaca en la llave usb
				system("cp /root/itaca/* /media/itaca/rootFLS/itaca/");
				break;

			// Restaurar backup 
			case 2:
		
       	        		// Copia el directorio /media/itaca/rootFLS en el sistema
       	        		// Hay que hacer un apagado ordenado para que se guarde la info en /rootFLS/itaca
				system("cp /media/itaca/rootFLS/itaca/* /root/itaca/");
	               		break;

			default:
       	        		printf("\nIncorrect option\n");
        	       		break;

			}
					
			break;

		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Hardware validation
		case 5:
			
			// Pregunta por la contraseña para proseguir
			printf("Password:");
			system("stty -echo");
			scanf("%s",password);
			system("stty echo");
	
			if ( !strcmp(password, "1f0t0nica1") ) {

				// Obtiene los string de las Mac
				fp = popen("ifconfig eth0|grep HWaddr|awk '{print $5}'", "r");
				if (fp == NULL) {
					printf("Error executing script: validation not completed. Exit.\n");
					return 1;
				}

				fgets(strMacEth0, sizeof(strMacEth0)-1, fp);
				pclose(fp);

				fp = popen("ifconfig eth1|grep HWaddr|awk '{print $5}'", "r");
				if (fp == NULL) {
					printf("Error executing script: validation not completed. Exit.\n");
					return 1;
				}

				fgets(strMacEth1, sizeof(strMacEth1)-1, fp);
				pclose(fp);

				//printf("str Mac eth0 = %s\nstr Mac eth1 = %s\n", strMacEth0, strMacEth1);

				// Ahora hay que eliminar los dos puntos y concatenar los dígitos hexadecimales
				strcpy(strEth0, "0x");
				str = strtok (strMacEth0, ":");
				strcat(strEth0, str);
				strcat(strEth0, strtok(NULL, ":"));
				strcat(strEth0, strtok(NULL, ":"));
				strcat(strEth0, strtok(NULL, ":"));
				strcat(strEth0, strtok(NULL, ":"));
				strcat(strEth0, strtok(NULL, ":"));

				strcpy(strEth1, "0x");
				str = strtok (strMacEth1, ":");
				strcat(strEth1, str);
				strcat(strEth1, strtok(NULL, ":"));
				strcat(strEth1, strtok(NULL, ":"));
				strcat(strEth1, strtok(NULL, ":"));
				strcat(strEth1, strtok(NULL, ":"));
				strcat(strEth1, strtok(NULL, ":"));

				//printf("str eth0 = %s\n str eth1 = %s\n", strEth0, strEth1);
				// Y ahora convertir el string en un número
				lMacEth0 = (long long)(strtod(strEth0, NULL));
				lMacEth1 = (long long)(strtod(strEth1, NULL));

				valorcalculado = (lMacEth0 * 0x28660) + lMacEth1;

				printf("eth0 = %lld\n eth1 = %lld valorcalculado = %lld\n", lMacEth0, lMacEth1, valorcalculado);
	
				// Monta la partición en modo de escritura
				system("mount / -o rw,remount");
		
				/* Crea el fichero */
				fichero = fopen("/etc/conf.d/itaca", "w");
	
				/* escribe el valor calculado */
				fprintf(fichero, "%lld\n", valorcalculado);

				/* Cierra el fichero */
				fclose(fichero);

				/* Monta la partición en modo de lectura */
				system("mount / -o ro,remount");
	
				/* Informa que ha terminado correctamente */
				printf("\nValidation completed OK\n");			

				}

			else {
				printf("\n### Incorrect password. Exit ###\n");
			}

			break;

		// Print Hardware validation data
		case 6:
			
			// Obtiene los string de las Mac
			fp = popen("ifconfig eth0|grep HWaddr|awk '{print $5}'", "r");
			if (fp == NULL) {
				printf("Error executing script: validation not completed. Exit.\n");
				return 1;
			}

			fgets(strMacEth0, sizeof(strMacEth0)-1, fp);
			pclose(fp);

			fp = popen("ifconfig eth1|grep HWaddr|awk '{print $5}'", "r");
			if (fp == NULL) {
				printf("Error executing script: validation not completed. Exit.\n");
				return 1;
			}

			fgets(strMacEth1, sizeof(strMacEth1)-1, fp);
			pclose(fp);

			//printf("str Mac eth0 = %s\nstr Mac eth1 = %s\n", strMacEth0, strMacEth1);

			// Ahora hay que eliminar los dos puntos y concatenar los dígitos hexadecimales
			strcpy(strEth0, "0x");
			str = strtok (strMacEth0, ":");
			strcat(strEth0, str);
			strcat(strEth0, strtok(NULL, ":"));
			strcat(strEth0, strtok(NULL, ":"));
			strcat(strEth0, strtok(NULL, ":"));
			strcat(strEth0, strtok(NULL, ":"));
			strcat(strEth0, strtok(NULL, ":"));

			strcpy(strEth1, "0x");
			str = strtok (strMacEth1, ":");
			strcat(strEth1, str);
			strcat(strEth1, strtok(NULL, ":"));
			strcat(strEth1, strtok(NULL, ":"));
			strcat(strEth1, strtok(NULL, ":"));
			strcat(strEth1, strtok(NULL, ":"));
			strcat(strEth1, strtok(NULL, ":"));

			//printf("str eth0 = %s\n str eth1 = %s\n", strEth0, strEth1);
			// Y ahora convertir el string en un número
			lMacEth0 = (long long)(strtod(strEth0, NULL));
			lMacEth1 = (long long)(strtod(strEth1, NULL));

			printf("Code A = %lld\t Code B = %lld\n", lMacEth0, lMacEth1);
				
			break;

		// Introduce validation code
		case 7:
			
			printf("Code:");
			//system("stty -echo");
			scanf("%lld",&valorcalculado);
			//system("stty echo");	
	
			// Monta la partición en modo de escritura
			system("mount / -o rw,remount");
		
			/* Crea el fichero */
			fichero = fopen("/etc/conf.d/itaca", "w");
	
			/* escribe el valor calculado */
			fprintf(fichero, "%lld\n", valorcalculado);

			/* Cierra el fichero */
			fclose(fichero);

			/* Monta la partición en modo de lectura */
			system("mount / -o ro,remount");
	
			/* Informa que ha terminado correctamente */
			printf("\nValidation code updated\n");			

			break;

		
		// Tables and slitting control
		case 8:

			// Pregunta si se quiere activar o no la función de tablas y precorte
			printf("\n\nSelect:\n");
			printf("1 - Table-Slitting deactivated\n");
			printf("2 - Table-Slitting ACTIVATED\n");
			printf("\n");
			scanf("%d",&acceso);

			// Crea el fichero como un archivo nuevo
			fichero = fopen("/root/itaca/tablaprecorte.bin", "wb");

			switch (acceso) {

			// Desactivado: escribe un 0 en binario
			case 1:
				fputc(0,fichero);
				break;

			// Activado: escribe un 1 en binario
			case 2:
       	        		fputc(1,fichero);
               			break;

			default:
       	        		printf("\nIncorrect option\n");
               			break;

			}
		
			// Cierra el fichero
			fclose(fichero);

			// Monta la partición en modo de escritura
			system("mount / -o rw,remount");
		
			// Copia el fichero en el directorio de carga
			system("cp /root/itaca/tablaprecorte.bin /rootFLS/itaca");

			// Monta la partición en modo de lectura
			system("mount / -o ro,remount");
	
			// Informa que ha terminado correctamente
			printf("\nTables and slitting control changed OK\n");

			break;
///////////////////////////////////////////////////////////////////////////////////////////////////
		// Exit
		case 0:

			printf("\n### Exit ###\n");
			return 0;		
			break;

		///////////////////////////////////////////////////////////////////////////////////////////////////	
		default:
		       	printf("\nIncorrect option\n");
                	break;

		}
	
	}

	else {

		printf("\n### Incorrect password. Exit ###\n");

	}

return 0;
	
}
