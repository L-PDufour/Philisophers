# Philosophers

number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat

• Chaque programme doit prendre les arguments suivants :
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
    ◦ number_of_philosophers : Le nombre de philosophes, mais aussi le nombre
    de fourchettes.
    ◦ time_to_die (en millisecondes) : Si un philosophe n’a pas commencé à manger
    time_to_die millisecondes après le début de son précédent repas ou depuis le
    début de la simulation, il meurt.
    ◦ time_to_eat (en millisecondes) : Le temps qu’un philosophe prend à manger.
    Pendant ce temps, un philosophe doit garder ses deux fourchettes.
    ◦ time_to_sleep (en millisecondes) : Le temps qu’un philosophe passe à dormir.
    ◦ number_of_times_each_philosopher_must_eat (argument optionnel) : Si tous
    les philosophes ont mangé au moins number_of_times_each_philosopher_must_eat
    fois, la simulation prend fin. Si cet argument n’est pas spécifié, alors la simu-
    lation prend fin à la mort d’un philosophe.
• Chaque philosophe se voit assigner un numéro entre 1 et number_of_philosophers.
• Le philosophe numéro 1 est assis à côté du philosophe numéro number_of_philosophers.
Les autres suivent cette logique : philosophe numéro N est assis entre philosophe
numéro N - 1 et philosophe numéro N + 1.

Concernant les logs de votre programme :
• Tout changement d’état d’un philosophe doit être formatté comme suit :
    ◦ timestamp_in_ms X has taken a fork
    ◦ timestamp_in_ms X is eating
    ◦ timestamp_in_ms X is sleeping
    ◦ timestamp_in_ms X is thinking
    ◦ timestamp_in_ms X died
Remplacez timestamp_in_ms par le timestamp actuel en millisecondes
et X par le numéro du philosophe.
• Tout message affiché ne doit pas être mélangé avec un autre message.
• Il ne doit pas y avoir plus de 10 ms entre la mort d’un philosophe et l’affichage du
    message annonçant sa mort.
• Encore une fois, les philosophes doivent éviter de mourir.
# memset
´´´
#include <string.h>
void *memset(void *dest, int c, size_t count);
´´´
# usleep

# gettimeofday

# pthread_create


# pthread_detach

# pthread_join

# pthread_mutex_init

# pthread_mutex_destroy

# pthread_mutex_lock

# pthread_mutex_unlock  
