/**
 * GNU General Public License Version 3.0, 29 June 2007
 * User
 * Copyright (C) <2019>
 *      Authors: <amirkhaniansev>  <amirkhanyan.sevak@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Full notice : https://github.com/amirkhaniansev/tyche/tree/master/LICENSE
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/


namespace Tyche.TycheDAL.Models
{
    /// <summary>
    /// Model for user
    /// </summary>
    public class User 
    {
        /// <summary>
        /// Gets or sets Id
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// Gets or sets first name
        /// </summary>
        public string FirstName { get; set; }

        /// <summary>
        /// Gets or sets last name
        /// </summary>
        public string LastName { get; set; }

        /// <summary>
        /// Gets or sets username
        /// </summary>
        public string Username { get; set; }

        /// <summary>
        /// Gets or sets email
        /// </summary>
        public string Email { get; set; }

        /// <summary>
        /// Gets or sets is verified
        /// </summary>
        public bool IsVerified { get; set; }

        /// <summary>
        /// Gets or sets boolean value indicating user activity
        /// </summary>
        public bool IsActive { get; set; }

        /// <summary>
        /// Gets or sets profile picture url
        /// </summary>
        public string ProfilePictureUrl { get; set; }

        /// <summary>
        /// Gets or sets password hash
        /// </summary>
        public string PasswordHash { get; set; }
    }
}
