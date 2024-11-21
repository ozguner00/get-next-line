#include "get_next_line.h"
char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;
	
	if(!s)
		return NULL;
	i = ft_strlen(s);
	j = 0;
	while (i >= 0)
	{
		if (s[j] == (char)c)
			return ((char *)s + j);
		i--;
		j++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
char *ft_strdup(const char *s)
{
    size_t len;
    size_t i;
    char *dup;

    len = 0;
    while (s[len])
        len++;

    dup = malloc(len + 1);
    if (!dup)
        return NULL;

    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }

    dup[i] = '\0';

    return dup;
}
void* free_and_return_null(void* ptr, void* ptr2){
    free(ptr);
    free(ptr2);
    return NULL;
}

