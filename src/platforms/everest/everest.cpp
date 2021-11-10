/* SPDX-License-Identifier: Apache-2.0 */

#include "platforms/everest.hpp"

void Everest::enrollWith(PlatformManager& pm)
{
    pm.enrollPlatform("Everest", this);
}

void Everest::detectFrus(Notifier& notifier, Inventory* inventory)
{
    Tola tola(inventory);

    /* Cold-plug devices */
    tola.plug(notifier);

    /* Hot-plug devices */
    notifier.run();

    /* Clean up the application state but leave the inventory in-tact. */
    tola.unplug(notifier, tola.UNPLUG_RETAINS_INVENTORY);
}