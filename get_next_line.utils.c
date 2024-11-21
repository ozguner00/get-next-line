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

void* free_and_return_null(void* ptr, void* ptr2){
    free(ptr);
    free(ptr2);
    return NULL;
}

