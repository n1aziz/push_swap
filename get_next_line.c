/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azel-mah <azel-mah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:32:09 by azel-mah          #+#    #+#             */
/*   Updated: 2025/12/08 09:32:09 by azel-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(storage), NULL);
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (free(buffer), storage);
}

static char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	if (!storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*clean_storage(char *storage)
{
	char	*new_storage;
	int		i;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, i + 1, ft_strlen(storage) - i - 1);
	free(storage);
	if (!new_storage || new_storage[0] == '\0')
	{
		free(new_storage);
		return (NULL);
	}
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	storage = read_to_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	storage = clean_storage(storage);
	return (line);
}
