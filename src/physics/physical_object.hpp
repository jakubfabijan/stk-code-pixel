//  $Id: physical_object.hpp 839 2006-10-24 00:01:56Z hiker $
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006 Joerg Henrichs
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_PHYSICAL_OBJECT_HPP
#define HEADER_PHYSICAL_OBJECT_HPP

#include <string>

#include "irrlicht.h"
using namespace irr;

#include "btBulletDynamicsCommon.h"

#include "physics/user_pointer.hpp"
#include "utils/vec3.hpp"

class scene::IAnimatedMesh;
class XMLNode;

class PhysicalObject
{
public:
    enum bodyTypes {MP_NONE, MP_CONE, MP_BOX, MP_SPHERE};

protected:
    /** The shape of this object. */
    bodyTypes             m_body_type;
    /** The bullet collision shape. */
    btCollisionShape     *m_shape;
    /** The corresponding bullet rigid body. */
    btRigidBody          *m_body;
    /** Bullet's motion state for this object. */
    btDefaultMotionState *m_motion_state;
    /** The mass of this object. */
    float                 m_mass;
    /** The pointer that is stored in the bullet rigid body back to 
     *  this object. */
    UserPointer           m_user_pointer;
    /** This is the initial position of the object for the physics. */
    btTransform           m_init_pos;
    /** The irrlicht mesh for this object. */
    scene::IMesh         *m_mesh;
    /** The irrlicht scene node this object is attached to. */
    scene::ISceneNode    *m_node;
    /** Radius of the object - this obviously depends on the actual shape. */
    float                 m_radius;
public:
                 PhysicalObject (const XMLNode *node);
    virtual     ~PhysicalObject (); 
    void         update         (float dt);
    void         init           ();
    virtual void reset          ();
    /** Returns the rigid body of this physical object. */
    btRigidBody *getBody        ()          { return m_body; }
    virtual void handleExplosion(const Vec3& pos, bool directHit);
};  // PhysicalObject

#endif
/* EOF */

