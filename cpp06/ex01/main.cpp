/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:30:26 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/11/19 19:15:06 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *data = new Data;
	std::cout <<"data: " << data << std::endl;
	data->s1 = "Hello";
	data->b = 42;
	data->s2 = "World";

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "raw : "<< std::hex << raw << std::dec << std::endl;

	Data *deserialized = Serializer::deserialize(raw);

	std::cout << "s1: " << deserialized->s1 << std::endl;
	std::cout << "b: " << deserialized->b << std::endl;
	std::cout << "s2: " << deserialized->s2 << std::endl;

	std::cout << "––––––––––––––––––––––––––––––" << std::endl;
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "b: " << data->b << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
}