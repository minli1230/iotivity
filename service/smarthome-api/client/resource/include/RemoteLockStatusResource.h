/* ****************************************************************
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/
#ifndef SMARTHOME_API_CLIENT_REMOTELOCKSTAUS_H_
#define SMARTHOME_API_CLIENT_REMOTELOCKSTAUS_H_

#include <SHBaseRemoteResource.h>

namespace OIC
{
    namespace Service
    {
        namespace SH
        {
            class RemoteLockStatusResourceDelegate
            {
            public:
                virtual ~RemoteLockStatusResourceDelegate() {}

                virtual void onLock(ResultCode code) = 0;
                virtual void onUnLock(ResultCode code) = 0;
                virtual void onGetStatus(std::string status, ResultCode code) = 0;
            };

            class RemoteLockStatusResource: public SHBaseRemoteResource,
                    public SHBaseRemoteResourceDelegate
            {
            friend class SHBaseRemoteResourceBuilder;
            public:
                virtual ~RemoteLockStatusResource();

                void lock();
                void unlock();
                void getStatus();

                void setRemoteLockStatusResourceDelegate(
                        RemoteLockStatusResourceDelegate* delegate);

            protected:
                RemoteLockStatusResource();

            private:
                virtual void onGet(PropertyBundle bundle, ResultCode ret);
                virtual void onSet(PropertyBundle bundle, ResultCode ret);
                virtual void onObserve(PropertyBundle bundle, const ObserveResponse obsType,
                        ResultCode ret);

            private:
                RemoteLockStatusResourceDelegate *m_delegate;
            };
        }
    }
}
#endif /* SMARTHOME_API_CLIENT_REMOTELOCKSTAUS_H_ */