//
//  AVX2Backend.hpp
//  MNN
//
//  Created by MNN on 2021/05/16.
//  Copyright © 2018, Alibaba Group Holding Limited
//

#ifndef AVX2Backend_hpp
#define AVX2Backend_hpp

#include "backend/cpu/CPUBackend.hpp"
#include "core/Macro.h"
#include "core/TensorUtils.hpp"

namespace MNN {
class AVX2Backend : public CPUBackend {
public:
    virtual ~AVX2Backend();
    AVX2Backend(const CPURuntime* runtime, size_t flags);
    virtual Execution* onCreate(const std::vector<Tensor*>& inputs, const std::vector<Tensor*>& outputs,
                                const MNN::Op* op) override;
    virtual bool onAcquireBuffer(const Tensor* nativeTensor, StorageType storageType) override;

    virtual void onCopyBuffer(const Tensor* srcTensor, const Tensor* dstTensor) const override;

    int numberThread() const {
        return threadNumber();
    }
    static bool isValid();
};

} // namespace MNN

#endif /* AVX2Backend_hpp */
