//    OpenVPN -- An application to securely tunnel IP networks
//               over a single port, with support for SSL/TLS-based
//               session authentication and key exchange,
//               packet encryption, packet authentication, and
//               packet compression.
//
//    Copyright (C) 2012-2022 OpenVPN Inc.
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License Version 3
//    as published by the Free Software Foundation.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program in the COPYING file.
//    If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <utility>

#include <openvpn/random/randapi.hpp>

namespace openvpn {

// By convention, rng is crypto-strength while prng is not.
struct Rand2
{
    Rand2()
    {
    }

    Rand2(StrongRandomAPI::Ptr rng_arg,
          RandomAPI::Ptr prng_arg)
        : rng(std::move(rng_arg)),
          prng(std::move(prng_arg))
    {
    }

    Rand2(StrongRandomAPI::Ptr rng_arg)
        : rng(rng_arg),
          prng(rng_arg)
    {
    }

    bool defined() const
    {
        return rng && prng;
    }

    StrongRandomAPI::Ptr rng;
    RandomAPI::Ptr prng;
};

} // namespace openvpn
