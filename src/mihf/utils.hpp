//==============================================================================
// Brief   : Utilities
// Authors : Simao Reis <sreis@av.it.pt>
//------------------------------------------------------------------------------
// ODTONE - Open Dot Twenty One
//
// Copyright (C) 2009-2011 Universidade Aveiro
// Copyright (C) 2009-2011 Instituto de Telecomunicações - Pólo Aveiro
//
// This software is distributed under a license. The full license
// agreement can be found in the file LICENSE in this distribution.
// This software may not be copied, modified, sold or distributed
// other than expressed in the named license agreement.
//
// This software is distributed without any warranty.
//==============================================================================

#ifndef ODTONE_MIHF_UTILS_HPP
#define ODTONE_MIHF_UTILS_HPP

///////////////////////////////////////////////////////////////////////////////
#include "transmit.hpp"
#include "local_transaction_pool.hpp"
#include "address_book.hpp"
#include "link_book.hpp"

#include <odtone/base.hpp>
#include "meta_message.hpp"
#include <odtone/mih/types.hpp>

#include <boost/function.hpp>
#include <boost/bind.hpp>
///////////////////////////////////////////////////////////////////////////////

namespace odtone { namespace mihf { namespace utils {

/**
 * Send a message using a TCP socket.
 *
 * @param io The io_service object that Link SAP I/O Service will use to
 * dispatch handlers for any asynchronous operations performed on
 * the socket.
 * @param msg The output message.
 * @param ip The IP address of the destination of the message.
 * @param port The port of the destination of the message.
 */
void tcp_send(boost::asio::io_service &io,
	      meta_message_ptr &msg,
	      const char *ip,
	      uint16 port);

/**
 * Send a message using an UDP socket.
 *
 * @param io The io_service object that Link SAP I/O Service will use to
 * dispatch handlers for any asynchronous operations performed on
 * the socket.
 * @param msg The output message.
 * @param ip The IP address of the destination of the message.
 * @param port The port of the destination of the message.
 */
void udp_send(boost::asio::io_service &io,
	      meta_message_ptr &msg,
	      const char *ip,
	      uint16 port);

/**
 * Forward the request to its destination.
 *
 * @param in The MIH Message to forward.
 * @param lpool The local transaction pool module.
 * @param t The transmit module.
 */
void forward_request(meta_message_ptr &in,
		     local_transaction_pool &lpool,
		     transmit &t);

/**
 * Check if the message destination is this MIHF.
 *
 * @param msg The input message.
 * @return True if this MIHF is the message destination or false otherwise.
 */
bool this_mihf_is_destination(meta_message_ptr &msg);

/**
 * Check if the message is a multicast message.
 *
 * @param msg The input message.
 * @return True if this is a multicast message or false otherwise.
 */
bool is_multicast(meta_message_ptr &msg);

/**
 * Update the capabilities of the local MIHF.
 *
 * @param abook The address book module.
 * @param lbook The link book module.
 */
void update_local_capabilities(address_book &abook, link_book &lbook);


} /* namespace utils */ } /* namespace mihf */ } /* namespace odtone */

#endif
