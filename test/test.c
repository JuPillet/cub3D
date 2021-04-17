#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int	main()
{
	static t_pov *pov;
	
	printf("%p\n", pov);
	pov = (t_pov*)malloc(1 * sizeof(t_pov));
	printf("%p, %p\n", pov, pov->scene);
	pov->scene = (t_scene *)malloc(1 * sizeof(t_scene));
	printf("%p, %p, %p\n", pov, pov->scene, pov->scene->a_light);
	pov->scene->a_light = (t_a_light *)malloc(1 * sizeof(t_a_light));
	printf("%p, %p, %p, %p\n", pov, pov->scene, pov->scene->a_light, pov->scene->a_light->is);
	pov->scene->a_light->is = (t_bool *)malloc(1 * sizeof(t_bool));
	printf("%p, %p, %p, %p, %d\n", pov, pov->scene, pov->scene->a_light, pov->scene->a_light->is, *pov->scene->a_light->is);
	*pov->scene->a_light->is = TRUE;
	printf("%p, %p, %p, %p, %d\n", pov, pov->scene, pov->scene->a_light, pov->scene->a_light->is, *pov->scene->a_light->is);
	free(pov->scene->a_light->is);
	free(pov->scene->a_light);
	free(pov->scene);
	free(pov);
	return (0);
}
